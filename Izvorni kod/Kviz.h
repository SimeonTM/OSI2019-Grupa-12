#ifndef KVIZ_H_INCLUDED
#define KVIZ_H_INCLUDED

#include <stdio.h>
#include <string.h>

               typedef struct
               {
                   int length;
                   int correct[10];
                   char question[10][101];
                   char first_answer[10][26];
                   char second_answer[10][26];
                   char third_answer[10][26];
               }KVIZ;                    //sadrzi pitanja i odgovore kviza(pitanja i
                                          //odgovori su pohranjeni u matricama-svakom pitanju odgovara po jedna vrsta iz matrica)

               void Read_Quiz(KVIZ*);    //kviz se cita iz fajla
               void Write_Quiz(KVIZ*);   //kviz de upisuje u fajl

               void Play_Quiz(KVIZ*);                      //igranje kviza
               void Delete_Question(KVIZ*,int);             //brisanje pitanja iz kviza prema rednom broju pitanja
               void Add_Question(KVIZ*,const char*,const char*,const char*,const char*,int);  //dodavanje pitanja u kviz
#endif // KVIZ_H_INCLUDED

