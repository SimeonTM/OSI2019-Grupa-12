#include "Sortiranje.h"


                 void sortiraj(const LISTA *src,int (*f)(const NODE*,const NODE*))
                 {
                     NODE *p=src->head,*q;

                     for(;p->right != NULL;p=p->right)            //prolazi se kroz sve clanove liste i u svakoj
                     {                                  //iteraciji se nalazi najmanji nesortirani element
                         q=p->right;

                         while(q != NULL)
                         {
                             if(!(*f)(p,q))            //sortiranje se vrsi u rastucem poretku
                             {
                                 DOGADJAJ temp=p->info;
                                 p->info=q->info;
                                 q->info=temp;
                             }
                             q=q->right;
                         }
                     }
                 }


                 int Sort_By_Name(const NODE *src1,const NODE *src2)
                 {
                     return (strcmp(src1->info.naziv,src2->info.naziv) <= 0)?1:0;

                 }


                  int Sort_By_Location(const NODE *src1,const NODE *src2)
                  {
                      return (strcmp(src1->info.lokacija,src2->info.lokacija) <= 0)?1:0;
                  }


                  int Sort_By_Category(const NODE *src1,const NODE *src2)
                  {
                      return (strcmp(src1->info.vrsta_dogadjaja,src2->info.vrsta_dogadjaja) <= 0)?1:0;
                  }



                  int Sort_By_Comments(const NODE *src1,const NODE *src2)
                  {
                      return (src1->info.koment.broj < src2->info.koment.broj)?1:0;
                  }



                  int Sort_By_Time(const NODE *src1,const NODE *src2)
                  {
                      const DOGADJAJ *p=&(src1->info),*q=&(src2->info);

                      if(p->datum.godina == q->datum.godina && p->datum.mjesec == q->datum.mjesec && p->datum.dan == q->datum.dan)//ako oba dogadjaja imaju isti mjesec,dan i godinu
                      return 1;

                      else if(p->datum.godina == q->datum.godina && p->datum.mjesec == q->datum.mjesec) //ako imajz istu godinu i mjesec
                      return (p->datum.dan < q->datum.dan)?1:0;

                      else if(p->datum.godina == q->datum.godina)                //ako imaju samo istu godinu
                      return (p->datum.mjesec < q->datum.mjesec)?1:0;

                      else
                      return (p->datum.godina < q->datum.godina)?1:0;          //ako si im svi svi atributi razliciti
                   }




                  int Sort_By_Description(const NODE *src1,const NODE *src2)
                  {
                      return (strlen(src1->info.vrsta_dogadjaja) < strlen(src2->info.vrsta_dogadjaja))?1:0;
                  }

