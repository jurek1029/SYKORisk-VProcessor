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
    imm = (T & IMM_MASK);

	printf("Wykonam LUI, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("LUI: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	printf("LUI: imm: 0x%08lx \r\n", imm);
    setRegister(rd, imm);
    printf("LUI: stan rd %d : 0x%08lx\r\n", rd, getRegister(rd));    
    incPC();
}