#include <stdio.h>
#include "merror.h"
#include "types.h"

CodeType    MEMC[MAX_ADDRESS+1];    //obszar pami�ci kodu 
DataType    MEMD[MAX_ADDRESS+1];    //obszar pami�ci danych
DataType    REG[MAX_REGISTER+1];    //deklaracja przechowywania rejestr�w

AddressType   PC;                   //licznik rozkaz�w
AddressType IP;
DataType    FLAGS;                  //flagi procesora

void loadMEMC(char *file){          //�adowanie pami�ci kodu z pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMC file not found (%s)!\n", file);
        exit(-2);
    }
    fseek(file_ptr, 0, SEEK_SET);
    fread(MEMC, MAX_ADDRESS+1, 1, file_ptr);
    fclose(file_ptr);
}

void loadMEMD(char *file){        //�adowanie pami�ci danych z pliku
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMD file not found (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fread(MEMD, sizeof(MEMD), 1, file_ptr);
    fclose(file_ptr);
}

void loadREGS(char *file){        //�adowanie stanu rejestr�w i PC z pliku
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMD file not found (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fread(REG, sizeof(REG), 1, file_ptr);        //Ladowanie stanu rejestr�w
    fread(&PC, sizeof(AddressType), 1, file_ptr);   //Ladowanie stanu PC (w pliku jest za kopia rejestr�w)
    fread(&FLAGS, sizeof(DataType), 1, file_ptr);   //Ladowanie stanu rejestru floagowe (w pliku jest za kopia PC)
    fclose(file_ptr);
}

void saveMEMD(char *file){        //zapisz zawarto�� pami�ci danych do pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "wb");
    if(!file_ptr){
        printf("MEMD cannot open to write (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fwrite(MEMD, sizeof(MEMD), 1, file_ptr);
    fclose(file_ptr);
}

void saveREGS(char *file){        //zapisz zawarto�� rejestr�w i PC do pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "wb");
    if(!file_ptr){
        printf("REGS cannot open to write (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fwrite(REG, sizeof(REG), 1, file_ptr);
    fwrite(&PC, sizeof(AddressType), 1, file_ptr);
    fwrite(&FLAGS, sizeof(DataType), 1, file_ptr);
    fclose(file_ptr);
}

CodeType getMEMC(AddressType p){
    if(p>MAX_ADDRESS)               //Czy odwolanie nie siega poza pamiec kodu
        merror(OUT_OF_CODE_MEMORY_SPACE_ERROR, p);
    return MEMC[p];
}

DataType getMEMD(AddressType p){
    if(p>MAX_ADDRESS)               //Czy odwolanie nie siega poza pamiec danych
        merror(OUT_OF_DATA_MEMORY_SPACE_ERROR, p);
    return MEMD[p];
}

void setMEMD(AddressType p, DataType v) {
	if (p > MAX_ADDRESS)               //Czy odwolanie nie siega poza pamiec danych
		merror(OUT_OF_DATA_MEMORY_SPACE_ERROR, p);
	MEMD[p] = v;
}

void setPC(AddressType v){
    PC=v;
}

AddressType getPC(void){
    return PC;
}

void incPC(void){
    PC++;
}

DataType getRegister(int n){
    if(n>MAX_REGISTER)               //Czy odwolanie nie siega poza zdefiniowany zestaw rejestrow
        merror(INVALID_REGISTER_GET, n);
    return REG[n];
}

void setRegister(int n, DataType v){
	printf("setRegister write to:%d v:0x%08lx \n", n,v);
    if(n>MAX_REGISTER)               //Czy odwolanie nie siega poza zdefiniowany zestaw rejestrow
        merror(INVALID_REGISTER_SET, n);
    REG[n]=v;
}

void setFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_SET_OF_FLAGS_BIT, b);
    FLAGS = FLAGS | (1<<b);
}

void resetFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_RESET_OF_FLAGS_BIT, b);
    FLAGS = FLAGS & (~(1<<b));
}

int getFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_GET_OF_FLAGS_BIT, b);
    return FLAGS & (1<<b);
}
