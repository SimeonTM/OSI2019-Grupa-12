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

                      CATEGORY Read_Catg_File();
                      void Write_Catg_File(CATEGORY);

                      void Write_Catg(CATEGORY);
                      char* Search_Catg(CATEGORY,const char*);
                      void Delete_Catg_Arr(CATEGORY*);

                      void Add_Catg(CATEGORY*,const char*);
                      void Delete_Catg(CATEGORY*,const char*);



#endif // KATEGORIJA_H_INCLUDED
