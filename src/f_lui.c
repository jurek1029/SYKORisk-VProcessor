#include "types.h"
#include "mem_abs.h"

#define RD_MASK 0xF80
#define RD_SHIFT 7
#define IMM_MASK 0xFFFFF000
#define IMM_SHIFT 12

void F_LUI(CodeType T){
    AddressType rd;
    CodeType imm;

    rd = (T & RD_MASK) >> RD_SHIFT;
    imm = (T & IMM_MASK) >> IMM_SHIFT;
	
    setRegister(rd, imm);
	printf("Wykonam LUI, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
    //printf("stan rejestru 0x%08lx : 0x%08lx\r\n", rd, getRegister(rd));    
    incPC();
}