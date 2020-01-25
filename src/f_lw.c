#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_RS1 0xF8000
#define MASK_OFFSET 0xFFF00000

#define SHIFT_RD 7
#define SHIFT_RS1 15
#define SHIFT_OFFSET 20
#define GET(name) (T & MASK_##name) >> SHIFT_##name 


void F_LW(CodeType T) {
	AddressType rd, rs1, offset;

	rd = GET(RD);
	rs1 = GET(RS1);
	offset = GET(OFFSET);

	printf("Wykonam LW, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("LW: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	printf("LW: rs1 adres: %d data: 0x%08lx \r\n", rs1, getRegister(rs1));
	printf("LW: offset: 0x%08lx \r\n", offset);

	setRegister(rd, getMEMD(getRegister(rs1) + offset));
	printf("LW after: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	incPC();
}