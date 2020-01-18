#include "types.h"
#include "mem_abs.h"

#define RD_MASK 0xF80
#define RD_SHIFT 7
#define RS1_MASK 0xF8000
#define RS1_SHIFT 15

// rd - rejestr w ktorym zapisywany jest aktualny PC
// rs1 - rejestr w ktorym przechowywany jest adres do skoku
void F_JALR(CodeType T){
    printf("Wykonam JALR, (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
    incPC();
    AddressType rs1;
    AddressType rd;
    rd = (T & RD_MASK) >> RD_SHIFT;
    rs1 = (T & RS1_MASK) >> RS1_SHIFT;
    setRegister(rd, getPC());
    setRegister(rs1, 0x1c);
    // printf("Stan rejestru rd: 0x%08lx\r\n", getRegister(rd));
    // printf("Stan rejestru rs1: 0x%08lx\r\n", getRegister(rs1));
    // printf("Skok pod adres wskazywany przez rejestr 0x%08lx\r\n", rs1);
    setPC(getRegister(rs1)/4);
    printf("Wykonano JALR, (PC=0x%08lx)\r\n", getPC());
}
