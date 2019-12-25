#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Kategorija.h"


                    typedef struct
                    {
                        int godina,mjesec,dan;
                        int sat,minut;
                    }DATUM;

                    typedef struct
                    {
                        char komentar[3][51];
                        int broj;
                    }KOMENTAR;   //ova struktura predstavlja matricu u kojoj su komentari,a broj se odnosi na
                                 //popunjenost

                    typedef struct
                    {
                        DATUM datum;
                        char naziv[21],lokacija[21];
                        char opis[51];
                        KOMENTAR koment;
                        char vrsta_dogadjaja[16];

                    }DOGADJAJ;



                    typedef struct node
                    {
                        struct node *left,*right;       //cvor dvostruke ulancane liste
                        DOGADJAJ info;
                    }NODE;


                    typedef struct           //ova struktura sadrzi pointere na pocetak i kraj dvostruke ulancane liste
                    {
                        NODE *head,*tail;
                    }LISTA;


                    void Read_Dj(DOGADJAJ*,CATEGORY);  //cita dogadjaj sa konzole
                    void Write_Dj(DOGADJAJ*,int);      //pise dogadjaj na konzolu

                    void Header();                     //pise atribute dogadjaja na konzolu
                    void Footer();                     //pise zaglavlje

                    void Add_Dj(LISTA*,DOGADJAJ*);      //dodaje dogadjaj u listu
                    int Delete_Dj(LISTA*,const char*);  //brsie dogadjaj iz liste prema nazivu dogadjaja
                    NODE* Search_Dj(LISTA*,const char*);//trazi dogadaj u listi prema nazivu
                    void Delete_List(LISTA*);           //brise listi

                    int Read_File(LISTA*);               //cita dogadjaj iz fajla i upisuje u listu
                    int Write_File(LISTA*);              //pise dogadjaje iz liste u fajl


#endif // LISTA_H_INCLUDED
