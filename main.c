#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "merror.h"

#define FUNCT3_MASK 0x7000
#define FUNCT7_MASK 0xFE000000
#define FUNCT3_SHIFT 12
#define FUNCT7_SHIFT 25
//naglowki poszczegolnych opcodow 
void F_JAL(CodeType T);
void F_JALR(CodeType T);
void F_ADD(CodeType T);
void F_LUI(CodeType T);

//wzorce opcodow
#define ID_JAL 0x6F
#define ID_JALR 0x67
#define ID_LUI 0x37
#define ID_ADD_R1_R2 0x33

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
        printf("Pobrano instrukcje (T=0x%08lx)\r\n", T);
        CodeType i;
        i = (T & 0x7F); //wyluskanie samego opcode
        switch(i){
            case ID_JAL:          //wywolac instrukcje JAL
                F_JAL(T);
                break;
            case ID_JALR:
                if ((T & FUNCT3_MASK) >> FUNCT3_SHIFT == 0x0) F_JALR(T);
                break;
            case ID_LUI:
                F_LUI(T);
                break;
            case ID_ADD_R1_R2:
                if (((T & FUNCT3_MASK) >> FUNCT3_SHIFT == 0x0) && ((T & FUNCT7_MASK) >> FUNCT7_SHIFT == 0x0)) F_ADD(T);
                break;
            default:
                printf("Wykryto nieznana instrukcje (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
                printf("Wyluskany opcode (T=0x%08lx)\r\n", i);
                saveMEMD("file_data.bin");      //zapisz zawarto�� pami�ci danych do pliku
                saveREGS("file_reg_out.bin");   //zapisz zawarto�� rejestr�w i PC do pliku 
                return -1;
        }
    }
    saveMEMD("file_data_out.bin");      //zapisz zawarto�� pami�ci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawarto�� rejestr�w i PC do pliku
    return 0;
}
