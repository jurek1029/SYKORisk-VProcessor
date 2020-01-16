#include "types.h"
#include "mem_abs.h"

void F_JMP(void){
    printf("0x%04x: JMP MEMC[0x%04x]=0x%04x\n", getPC(), getPC()+1, getMEMC(getPC()+1));

    setPC(getMEMC(getPC()+1));
}
