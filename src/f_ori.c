#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_RS1 0xF8000
#define MASK_IMM 0xFFF00000

#define SHIFT_RD 7
#define SHIFT_RS1 15
#define SHIFT_IMM 20
#define GET(name) (T & MASK_##name) >> SHIFT_##name 

void F_ORI(CodeType T) {
	AddressType rd, rs1;
	DataType imm;

	rd = GET(RD);
	rs1 = GET(RS1);
	imm = GET(IMM);

	printf("Wykonam ORI, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("ORI: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	printf("ORI: rs1 adres: %d data: 0x%08lx \r\n", rs1, getRegister(rs1));
	printf("ORI: imm: 0x%08lx \r\n", imm);
	if (imm & 0x800) imm = imm | 0xFFFFF800; //sign-extended
	setRegister(rd, getRegister(rs1) | imm);
	printf("ORI: adresReg 0x%08lx, dane 0x%08lx\r\n", rd, getRegister(rs1) | imm);
	incPC();
}