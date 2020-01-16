#include <stdio.h>

#include "types.h"
#include "mem_abs.h"
#include "merror.h"

//naglowki poszczegolnych opcodow 
void F_ADD1(void);
void F_ADD2(void);
void F_JMP(void);
//...

//wzorce opcodow 
#define ID_ADD_R1_R2            0x01
#define ID_ADD_R1_MEM_R2        0x02
#define ID_JMP                  0x03
//...

void merror(int i, int j){
    printf("ERROR code: 0x%08lx with arg. 0x%08lx at PC=0x%08lx\r\n", i, j, getPC());
    saveMEMD("file_data_out.bin");      //zapisz zawartoœæ pamiêci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawartoœæ rejestrów i PC do pliku
    exit(-1);
}

int main(void){
    CodeType T;                         //zmienna pomocnicza
    loadMEMC("file_code.bin");          //£adowanie pamiêci kodu z pliku 
    loadMEMD("file_data_in.bin");       //£adowanie pamiêci danych z pliku
    loadREGS("file_reg_in.bin");        //£adowanie stanu rejestrów z pliku
    setPC(0x0000);                      //Warunki pocz¹tkowe PC (RESET)
    for(;;){
        T=getMEMC(getPC());            //T=ID operacji i arg. wbudowanych
        switch((T & 0xF000)>>12){      //wy³uskanie w³aœciwego kodu operacji
            case ID_ADD_R1_R2:          //wywolac instrukcje ADD R1,R2
                F_ADD1();
                break;
            case ID_ADD_R1_MEM_R2:      //wywolac instrukcje ADD R1,[R2]
                F_ADD2();
                break;
            case ID_JMP:                //wywolac instrukcje JMP address
                F_JMP();
                break;
            default:
                printf("Wykryto nieznana instrukcje (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
                saveMEMD("file_data.bin");      //zapisz zawartoœæ pamiêci danych do pliku
                saveREGS("file_reg_out.bin");   //zapisz zawartoœæ rejestrów i PC do pliku 
                return -1;
        }
    }
    saveMEMD("file_data_out.bin");      //zapisz zawartoœæ pamiêci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawartoœæ rejestrów i PC do pliku
    return 0;
}
