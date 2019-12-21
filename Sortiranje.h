#ifndef SORTIRANJE_H_INCLUDED
#define SORTIRANJE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "Lista.h"
#include "Kategorija.h"

                  void sortiraj(const LISTA*,int (*)(const NODE*,const NODE*));

                  int Sort_By_Name(const NODE*,const NODE*);
                  int Sort_By_Location(const NODE*,const NODE*);
                  int Sort_By_Category(const NODE*,const NODE*);
                  int Sort_By_Time(const NODE*,const NODE*);
                  int Sort_By_Comments(const NODE*,const NODE*);
                  int Sort_By_Description(const NODE*,const NODE*);

#endif // SORTIRANJE_H_INCLUDED
