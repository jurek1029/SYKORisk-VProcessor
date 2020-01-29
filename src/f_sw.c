#include "types.h"
#include "mem_abs.h"

#define MASK_RS1A 0xF8000
#define MASK_RS2D 0x1F00000
#define MASK_OFFSET_1 0xFE000000
#define MASK_OFFSET_0 0xF80

#define SHIFT_RS1A 15
#define SHIFT_RS2D 20
#define SHIFT_OFFSET_1 25
#define SHIFT_OFFSET_0 7
#define GET(name) (T & MASK_##name) >> SHIFT_##name 

void F_SW(CodeType T) {
	AddressType rs1a, rs2d, offset;

	rs1a = GET(RS1A);
	rs2d = GET(RS2D);
	offset = GET(OFFSET_1) << 5 | GET(OFFSET_0);
	if (offset & 0x800) offset = offset | 0xFFFFF800; //sign-extended

	//printf("Wykonam SW, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	//printf("SW: ra adres: %d ra data: 0x%08lx \r\n", rs1a, getRegister(rs1a));
	//printf("SW: rd adres: %d rd data: 0x%08lx \r\n", rs2d, getRegister(rs2d));
	//printf("SW: offset: 0x%08lx \r\n", offset);
	
	setMEMD(getRegister(rs1a) + offset, getRegister(rs2d));
	//printf("SW: adresDanych 0x%08lx, dane 0x%08lx\r\n", getRegister(rs1a) + offset, getMEMD(getRegister(rs1a) + offset));
	incPC();
}