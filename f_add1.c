#include "types.h"
#include "mem_abs.h"

void F_ADD1(void){
    DataType R1=getMEMC(getPC()) & 0x000F;                  //identyfikacja numeru rejestru arg. 1
    DataType R2=(getMEMC(getPC()) & 0x00F0)>>4;             //identyfikacja numeru rejestru arg. 2

    printf("0x%04x: ADD R%d, R%d\n", getPC(), R1, R2);

    if((getRegister(R1) + getRegister(R2)) > MAX_DATA_VAL)
        setFlagsRegister(FLAG_C);                           //ustawienie flagi przeniesienia
    else
        resetFlagsRegister(FLAG_C);                         //wykasowanie flagi przeniesienia
        
    setRegister(R1, (getRegister(R1) + getRegister(R2)) % MAX_DATA_VAL);    //w³aœciwe obliczenie

    incPC();                                                //zwiêkszenie licznika rozkazów
}
