#include "types.h"
#include "mem_abs.h"

#define OFFSET_1_4 0xF00
#define OFFSET_5_10 0x7E000000
#define OFFSET_11 0x80
#define OFFSET_12 0x80000000
#define RS1_MASK 0xF8000
#define RS2_MASK 0x1F00000

#define SHIFT_1_4 8
#define SHIFT_5_10 21
#define SHIFT_11 3
#define SHIFT_12 19
#define RS1_SHIFT 15
#define RS2_SHIFT 20

CodeType offset;

void F_BLTU(CodeType T) {
    DataType R1;
    DataType R2;
    R1 = (T & RS1_MASK) >> RS1_SHIFT;
    R2 = (T & RS2_MASK) >> RS2_SHIFT;



    offset = (T & OFFSET_1_4)>>SHIFT_1_4;
    offset = offset | (T & OFFSET_5_10)>>SHIFT_5_10;
    offset = offset | (T & OFFSET_11)<<SHIFT_11;
    offset = offset | (T & OFFSET_12)>>SHIFT_12;
    printf("Offset 0x%08lx\r\n", offset/2);
    incPC();
    if(getRegister(R1) < getRegister(R2))
    {
        setPC(getPC()-1+offset/2);
    }
}