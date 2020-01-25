#include "types.h"
#include "mem_abs.h"

#define MASK_RD 0xF80
#define MASK_OFFSET 0xFFFFF000

#define SHIFT_RD 7
#define GET(name) (T & MASK_##name) >> SHIFT_##name 

void F_AUIPC(CodeType T) {
	AddressType rd;
	DataType offset;

	rd = GET(RD);
	offset = (T & MASK_OFFSET); //place zeros in lowest bits

	printf("Wykonam AUIPC, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
	printf("AUIPC: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	printf("AUIPC: offset: 0x%08lx \r\n", offset);
	setRegister(rd, offset + getPC()); // fils lowest 12-bits with zeros and stores in rd
	
	printf("AUIPC after: rd adres: %d data: 0x%08lx \r\n", rd, getRegister(rd));
	incPC();
}