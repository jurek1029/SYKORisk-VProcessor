#include "types.h"
#include "mem_abs.h"

#define RD_MASK 0xF80
#define RS1_MASK 0xF8000
#define RS2_MASK 0x1F00000
#define RD_SHIFT 7
#define RS1_SHIFT 15
#define RS2_SHIFT 20

void F_ADD(CodeType T){
    AddressType rd;  // rejestr przeznaczenia
    DataType R1;
    DataType R2;
    rd = (T & RD_MASK) >> RD_SHIFT;
    R1 = (T & RS1_MASK) >> RS1_SHIFT;                  //identyfikacja numeru rejestru arg. 1
    R2 = (T & RS2_MASK) >> RS2_SHIFT;             //identyfikacja numeru rejestru arg. 2

    printf("0x%04x: ADD R%d, R%d\n", getPC(), R1, R2);

    if((getRegister(R1) + getRegister(R2)) > MAX_DATA_VAL)
        setFlagsRegister(FLAG_C);                           //ustawienie flagi przeniesienia
    else
        resetFlagsRegister(FLAG_C);                         //wykasowanie flagi przeniesienia
        
    setRegister(rd, (getRegister(R1) + getRegister(R2)) % MAX_DATA_VAL);    //w�a�ciwe obliczenie
    printf("rd: %d\r\n", getRegister(rd));
    //printf("%d\r\n",getFlagsRegister(FLAG_C));
    incPC();                                                //zwi�kszenie licznika rozkaz�w
}
