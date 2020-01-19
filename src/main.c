#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "merror.h"

#define FUNCT3_MASK 0x7000
#define FUNCT3_SHIFT 12

//naglowki poszczegolnych opcodow 
void F_SW(CodeType T);
void F_LW(CodeType T);
void F_LHU(CodeType T);
void F_JAL(CodeType T);
void F_AUIPC(CodeType T);
void F_ADD(CodeType T);
void F_ORI(CodeType T);
void F_LUI(CodeType T);
void F_JALR(CodeType T);
void F_BLTU(CodeType T);
void F_AND(CodeType T);


//wzorce opcodow
#define ID_SW 0x2023
#define ID_LW 0x2003
#define ID_LHU 0x5003
#define ID_JAL 0x6F
#define ID_AUIPC 0x17  
#define ID_ADD_R1_R2 0x0033
#define ID_ORI 0x6013 
#define ID_LUI 0x37
#define ID_JALR 0x0067
#define ID_BLTU 0x6063
#define ID_AND 0x7033



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
        i = (T & 0x7F);				//wyluskanie samego opcode
        switch(i){
            case ID_JAL:			//wywolac instrukcje JAL
                F_JAL(T);
                break;
			case ID_AUIPC:			//wywolac instrukcje AUIPC
                F_AUIPC(T);
                break;
			case ID_LUI:			//wywolac instrukcje LUI
				F_LUI(T);
				break;
			default:
				switch (T & 0x707F) //wyluskanie opcode i funct3
				{
				case ID_SW:			//wywolac instrukcje SW 
					F_SW(T);
					break;
				case ID_LW:			//wywolac instrukcje LW 
					F_LW(T);
					break;
				case ID_LHU:		//wywolac instrukcje LHU 
					F_LHU(T);
					break;
				case ID_ADD_R1_R2:	//wywolac instrukcje ADD 
					F_ADD(T);
					break;
				case ID_ORI:		//wywolac instrukcje ORI 
					F_ORI(T);
					break;
				case ID_JALR:		//wywolac instrukcje JALR 
					F_JALR(T);
					break;
				case ID_BLTU:		//wywolac instrukcje BLTU 
					F_BLTU(T);
					break;
				case ID_AND:		//wywolac instrukcje AND 
					F_AND(T);
					break;
				default:
					printf("Wykryto nieznana instrukcje (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
					printf("Wyluskany opcode (T=0x%08lx)\r\n", i);
					saveMEMD("file_data.bin");      //zapisz zawarto�� pami�ci danych do pliku
					saveREGS("file_reg_out.bin");   //zapisz zawarto�� rejestr�w i PC do pliku 
					return -1;
				}
				break;
            
        }
    }
    saveMEMD("file_data_out.bin");      //zapisz zawarto�� pami�ci danych do pliku
    saveREGS("file_reg_out.bin");       //zapisz zawarto�� rejestr�w i PC do pliku
    return 0;
}
