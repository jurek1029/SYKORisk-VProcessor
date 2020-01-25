#ifndef __TYPES_H__
#define __TYPES_H__
#include <stdint.h>
#include <stdio.h> //to fix warnings
#include <stdlib.h>//tp fix warnings

//definicje nowych typow danych
typedef uint32_t       DataType;
typedef uint32_t      CodeType;
typedef unsigned short      AddressType;

//najwieksze wartosci 
#define MAX_ADDRESS         0xFFFF
#define MAX_DATA_VAL        0xFFFFFFFF

//Numer ostatniego rejestru
#define MAX_REGISTER        31

//Znaczenie flag
#define FLAG_C              0x01

#endif //__TYPES_H__
