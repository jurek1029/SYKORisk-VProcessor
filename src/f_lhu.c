#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_RS1 0xF8000

#define SHIFT_RD 7
#define SHIFT_RS1 15

void F_LHU(CodeType T) {
	AddressType rd, rs1;
	CodeType imm;

	rd = (T & MASK_RD) >> SHIFT_RD;
	rs1 = (T & MASK_RS1) >> SHIFT_RS1;
	DataType d = (getMEMD(rs1) & 0xFFFF); // zero extends => 16bit to 32 bit aka change first 16bit to 0

	setRegister(rd, d);
	printf("Wykonam LHU, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("stan rejestru 0x%08lx : 0x%08lx\r\n", rd, getRegister(rd));
	incPC();
}