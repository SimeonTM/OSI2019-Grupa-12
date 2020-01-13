#ifndef KORISNIK_SA_NALOGOM_H_INCLUDED
#define KORISNIK_SA_NALOGOM_H_INCLUDED

#include "Lista.h"
#include "Kviz.h"
#include "Kategorija.h"
#include "Grad.h"
#include "Sortiranje.h"
#include "Korisnik_bez_naloga.h"
#include <conio.h>

                    int Check_Password();                             //orijava na sistem
                    void Sort_events(LISTA*);                         //sortiranje dogadjaja

                    void Add_New_Category(CATEGORY*);                 //dodavanje nove kategorije
                    void Delete_Category(CATEGORY*,LISTA*);           //brisanje zeljene kategorije

                    void Delete_Event(LISTA*);                        //brisanje dogadjaja
                    void Add_New_Event(LISTA*,CATEGORY*);             //dodavanje novog dogadjaja
                    void Change_Event(LISTA*,CATEGORY*);              //izmjena postojeceg dogadjaja

                    void Change_Quiz();                               //izmjena kviza
                    void Change_City();                               //izmjena grada

                    void Footer_Adv();
                    void Print_Menu_Advanced();
#endif // KORISNIK_SA_NALOGOM_H_INCLUDED
