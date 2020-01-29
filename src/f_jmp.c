#include "types.h"
#include "mem_abs.h"

#define RD_MASK 0xF80
#define RD_SHIFT_BITS 7

// Makra do wyluskania offsetu
#define OFFSET_1_10 0x7FE00000
#define OFFSET_11 0x100000
#define OFFSET_12_19 0xFF000
#define OFFSET_20 100000

#define SHIFT_1_10 20
#define SHIFT_11 9
#define SHIFT_12_19 0
#define SHIFT_20 11

CodeType offset;

void F_JAL(CodeType T){
	//printf("Wykonam JAL, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);

    offset = (T & OFFSET_1_10)>>SHIFT_1_10;
    offset = offset | (T & OFFSET_11)>>SHIFT_11;
    offset = offset | (T & OFFSET_12_19);
    offset = offset | (T & OFFSET_20)>>SHIFT_20;

    //printf("Offset 0x%08lx\r\n", offset);
    incPC();  // zwiekszenie PC na wszelki wypadek gdyby skok sie nie wykonal
    if ((T & RD_MASK)>>RD_SHIFT_BITS == 0x0) { // x0 only jump
        //printf("Wykonam J, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
        setPC(getPC()-1+offset/4);  // wpisanie adresu skoku do PC/IP
        //printf("Wykonano J, (PC=0x%08lx)\r\n", getPC());
    }
    else  if ((T & RD_MASK)>>RD_SHIFT_BITS >= 0x1){ // xa jump and link
        //printf("Wykonam JAL, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
        setRegister((T & RD_MASK)>>RD_SHIFT_BITS, getPC());  // zapisanie w rejestrze aktualnego PC
        setPC(getPC()-1+offset/4);  // wpisanie adresu skoku do PC/IP
        //printf("Wykonano JAL, (PC=0x%08lx)\r\n", getPC());
        //printf("Stan rejestru %d: %d\r\n",((T & RD_MASK)>>RD_SHIFT_BITS), getRegister((T & RD_MASK)>>RD_SHIFT_BITS));
    }
}
