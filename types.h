#ifndef __TYPES_H__
#define __TYPES_H__

//definicje nowych typow danych
typedef unsigned char       DataType;
typedef unsigned short      CodeType;
typedef unsigned short      AddressType;

//najwieksze wartosci 
#define MAX_ADDRESS         0xFFFF
#define MAX_DATA_VAL        0xFF

//Numer ostatniego rejestru
#define MAX_REGISTER        31

//Znaczenie flag
#define FLAG_C              0x01

#endif //__TYPES_H__
