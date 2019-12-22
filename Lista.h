#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Kategorija.h"

          // u datoteci DOGADJAJ su upisani dogadjaji u binarnom formatu

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


                    void Read_Dj(DOGADJAJ*,CATEGORY);
                    void Write_Dj(DOGADJAJ*,int);

                    void Header();
                    void Footer();

                    void Add_Dj(LISTA*,DOGADJAJ*);
                    int Delete_Dj(LISTA*,const char*);
                    NODE* Search_Dj(LISTA*,const char*);
                    void Delete_List(LISTA*);

                    int Read_File(LISTA*);
                    int Write_File(LISTA*);


#endif // LISTA_H_INCLUDED
