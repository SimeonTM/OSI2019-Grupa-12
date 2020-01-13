#ifndef KORISNIK_BEZ_NALOGA_H_INCLUDED
#define KORISNIK_BEZ_NALOGA_H_INCLUDED

#include "Kategorija.h"
#include "Lista.h"
#include "Kviz.h"
#include "Grad.h"
#include <time.h>

    void Print_All_Events(LISTA*);                     //pise sve dogadjaje
    void Print_Events_By_Category(LISTA*,CATEGORY);    //ispis dogadjaja prema kategoriji
    void Print_Events_By_Time(LISTA*,int);             //ispis dogadjaja prema vremenu odrzavanja
    void Quiz();                                       //igranje  kviza
    void Print_Front_Page(const char *);               //pise sadrzaj fajla na konzolu
    void Add_Comment_To_Event(LISTA*);                 //dodavanje komentara dogadjaju
    void Print_Menu();                                 //ispis menija sa ponudjenim opcijama
    void Print_City_User();                            //ispis grada na konzolu

#endif // KORISNIK_BEZ_NALOGA_H_INCLUDED
