#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_RS1 0xF8000
#define MASK_OFFSET 0xFFF00000

#define SHIFT_RD 7
#define SHIFT_RS1 15
#define SHIFT_OFFSET 20
#define GET(name) (T & MASK_##name) >> SHIFT_##name 


void F_LHU(CodeType T) {
	AddressType rd, rs1, offset;
	DataType data;
	rd = GET(RD);
	rs1 = GET(RS1);
	offset = GET(OFFSET);
	if (offset & 0x800) offset = offset | 0xFFFFF800; //sign-extended
	data = getMEMD((AddressType)getRegister(rs1) + offset) & 0x0000FFFF; // zero-extends first 16bits

	printf("Wykonam LHU, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("LHU: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	printf("LHU: rs1 adres: %d data: 0x%08lx \r\n", rs1, getRegister(rs1));
	printf("LHU: offset: 0x%08lx \r\n", offset);
	setRegister(rd, data);
	printf("LHU after: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	incPC();
}
