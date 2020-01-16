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
    saveMEMD("file_data_out.bin");      //zapisz zawarto�� pami�ci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawarto�� rejestr�w i PC do pliku
    exit(-1);
}

int main(void){
    CodeType T;                         //zmienna pomocnicza
    loadMEMC("file_code.bin");          //�adowanie pami�ci kodu z pliku 
    loadMEMD("file_data_in.bin");       //�adowanie pami�ci danych z pliku
    loadREGS("file_reg_in.bin");        //�adowanie stanu rejestr�w z pliku
    setPC(0x0000);                      //Warunki pocz�tkowe PC (RESET)
    for(;;){
        T=getMEMC(getPC());            //T=ID operacji i arg. wbudowanych
        switch((T & 0xF000)>>12){      //wy�uskanie w�a�ciwego kodu operacji
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
                saveMEMD("file_data.bin");      //zapisz zawarto�� pami�ci danych do pliku
                saveREGS("file_reg_out.bin");   //zapisz zawarto�� rejestr�w i PC do pliku 
                return -1;
        }
    }
    saveMEMD("file_data_out.bin");      //zapisz zawarto�� pami�ci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawarto�� rejestr�w i PC do pliku
    return 0;
}
