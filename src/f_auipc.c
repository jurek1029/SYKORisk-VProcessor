#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_IMM 0xFFFFF000

#define SHIFT_RD 7

void F_AUIPC(CodeType T) {
	AddressType rd;
	DataType imm;

	rd = (T & MASK_RD) >> SHIFT_RD;
	imm = (T & MASK_IMM);

	setRegister(rd, imm + getPC()); // fils lowest 12-bits with zeros and stores in rd
	printf("Wykonam AUIPC, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("stan rejestru 0x%08lx : 0x%08lx\r\n", rd, getRegister(rd));
	incPC();
}