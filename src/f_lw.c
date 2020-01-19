#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_RS1 0xF8000

#define SHIFT_RD 7
#define SHIFT_RS1 15


void F_LW(CodeType T) {
	AddressType rd, rs1;

	rd = (T & MASK_RD) >> SHIFT_RD;
	rs1 = (T & MASK_RS1) >> SHIFT_RS1;

	setRegister(rd, getMEMD(rs1));
	printf("Wykonam LW, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("stan rejestru 0x%08lx : 0x%08lx\r\n", rd, getRegister(rd));    
	incPC();
}