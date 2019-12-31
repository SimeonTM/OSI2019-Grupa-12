#ifndef GRAD_H_INCLUDED
#define GRAD_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdio.h>

          typedef struct
          {
              char niz[6][33];
              int current;
          }STRING;

          typedef struct
          {
              char naziv[33];
              char pseudonim[33];
              int populacija;
              char drzava[33];
              char lokacija[33];
              STRING naselja;
              STRING znamenitosti;
          }CITY;

          void Write_City(CITY*);         //upis grada u fajl
          void Read_City(CITY*);          //cita grad iz fajla
          void Print_City(CITY*);         //ispis grada na konzolu



#endif // GRAD_H_INCLUDED
