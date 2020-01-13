#ifndef SORTIRANJE_H_INCLUDED
#define SORTIRANJE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "Lista.h"
#include "Kategorija.h"

                  void sortiraj(const LISTA*,int (*)(const NODE*,const NODE*));  //sortiranje liste u rastucem poretku

                  int Sort_By_Name(const NODE*,const NODE*);        //poredjenje prema imenu
                  int Sort_By_Location(const NODE*,const NODE*);    //poredjenje prema lokaciji
                  int Sort_By_Category(const NODE*,const NODE*);    //poredjenje prema kategoriji
                  int Sort_By_Time(const NODE*,const NODE*);        //poredjenje  prema vremenu
                  int Sort_By_Comments(const NODE*,const NODE*);    //poredjenje prema broju komentara
                  int Sort_By_Description(const NODE*,const NODE*); //poredjenje prema duzini opisa

#endif // SORTIRANJE_H_INCLUDED
