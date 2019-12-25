#ifndef KATEGORIJA_H_INCLUDED
#define KATEGORIJA_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
            //u datoteci KATEGORIJA su upisani svi dogadjalji

                      typedef struct
                      {
                          int length;
                          char **niz;       //struktura predstavlja dvodimenizionalnu matricu
                      }CATEGORY;            // u kojoj su pohranjeni nazivi kategorija dogadjaja

                      CATEGORY Read_Catg_File();              //citanje kategorija iz fajla
                      void Write_Catg_File(CATEGORY);         //upis kategorija u fajl

                      void Print_Catg(CATEGORY);                     //ispis kategorija na konzolu
                      char* Search_Catg(CATEGORY,const char*);       //pretraga kategorije prema nazivu
                      void Delete_Catg_Arr(CATEGORY*);               //brisanje kategorije

                      void Add_Catg(CATEGORY*,const char*);         //dodavanje kategorije
                      void Delete_Catg(CATEGORY*,const char*);      //brisanje kategorije



#endif // KATEGORIJA_H_INCLUDED
