#include "types.h"
#include "mem_abs.h"

#define MASK_RS1A 0xF8000
#define MASK_RS2D 0x1F00000

#define SHIFT_RS1A 15
#define SHIFT_RS2D 20

void F_SW(CodeType T) {
	AddressType rs1a, rs2d;

	rs1a = (T & MASK_RS1A) >> SHIFT_RS1A;
	rs2d = (T & MASK_RS2D) >> SHIFT_RS2D;

	setMEMD(getRegister(rs1a), getRegister(rs2d))
	printf("Wykonam SW, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("stan danych 0x%08lx : 0x%08lx\r\n", rd, getMEMD(getRegister(rs1a)));
	incPC();
}