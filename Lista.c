#include "Lista.h"

               void Read_Dj(DOGADJAJ *pom,CATEGORY src)         //f-ja ucitava novi dogadjaj
               {
                   char temp[200]="";
                   int z;

                   do
                   {
                        printf("Unesite naziv dogadjaja:");
                        scanf("%s",temp);

                   }while(strlen(temp) > 20);
                   strcpy(pom->naziv,temp);

                   do
                   {
                        printf("Unesite lokaciju dogadjaja:");
                        scanf("%s",temp);

                   }while(strlen(temp) > 20);
                   strcpy(pom->lokacija,temp);


                   do
                   {
                       printf("Unesite opis dogadjaja:");
                       scanf("%s",temp);
                   }while(strlen(temp)>50);
                   strcpy(pom->opis,temp);

                     //na pocetku nema komentara
                   do
                   {
                       printf("Unesite komentar za dati dogadjaj:");
                       scanf("%s",temp);
                   }while(strlen(temp) > 50);
                   pom->koment.broj=1;      //na pocetku se nalazi samo jedan komentar
                   strcpy(pom->koment.komentar[0],temp);

                   do
                   {
                       Print_Catg(src);                                    //korisnik bira neku od ponudjenih kategorija
                       printf("Unesite redni broj zeljene kategorije:");
                       scanf("%d",&z);
                   }while(z<1 || z>src.length);
                   strcpy(pom->vrsta_dogadjaja,src.niz[z-1]);

                   int i,j,k;

                   do
                   {
                       printf("Unesite godinu desavanja:");          scanf("%d",&i);
                       printf("Unesite mjesec desavanja:");          scanf("%d",&j);
                       printf("Unesite dan desavanja:");             scanf("%d",&k);
                   }while(i<0 || i>9999 || j<1 || j>12 || k<1 || k>31);             //validacija godine i mjeseca
                   pom->datum.godina=i;        pom->datum.mjesec=j;     pom->datum.dan=k;


                   do
                   {
                       printf("Unesite sat i minutu odrzavanja:\n");
                       printf("Sat:");        scanf("%d",&i);
                       printf("Minuta:");     scanf("%d",&j);
                   }while(i<0 || i>23 || j<0 || j>59);           //validacija minuta i sekundi
                   pom->datum.sat=i;          pom->datum.minut=j;
               }






               void Add_Dj(LISTA *lista,DOGADJAJ *value)                   //ova funkcija dodaje novi dogadjaj u listu
               {

                     NODE *novi=(NODE *)malloc(sizeof(NODE));    //kreiranje novog cvora i njegova pocetna inicijalizacija
                     novi->info = *value;
                     novi->left=novi->right=NULL;

                     if(lista->head == NULL)               //ako je lista prazna
                     {
                         lista->head=lista->tail=novi;
                     }

                     else
                     {
                         NODE *q=lista->tail;           //dodavanje na kraj
                         q->right=novi;
                         novi->left=q;
                         lista->tail=novi;
                     }
               }




               NODE* Search_Dj(LISTA *lista,const char *key)
               {
                   NODE *q=lista->head;
                                                     //pretraga dogadjaja
                   for(;q != NULL;q=q->right)
                   if(!strcmp(key,q->info.naziv))
                   return q;

                   return NULL;
               }



               int Delete_Dj(LISTA *lista,const char *key)
               {
                   NODE *q=Search_Dj(lista,key);

                   if(q == NULL)  return 0;    //ako dogadjaj ne postoji
                   else
                   {
                       NODE *p1=q->left , *p2=q->right;
                       p1->right=p2;
                       p2->left=p1;
                       free(q);
                   }

                   return 1;
               }




               void Delete_List(LISTA *lista)   //brisanje liste
               {
                   while(lista->head != NULL)
                   {
                       NODE *q=lista->head;
                       lista->head=q->right;
                       free(q);
                   }

                   lista->tail=NULL;
               }



               void Header()
               {
                   printf(" %-3s  %-20s  %-20s  %-15s  %-10s  %-5s  %-50s\n","RB","NAZIV","LOKACIJA","KATEGORIJA","DATUM","VREME","OPIS");
               }

               void Footer()
               {
                   printf("=======================================================================================================================================\n");
               }



               void Write_Dj(DOGADJAJ *pom,int rb)  //ispis jednog dogadjaja
               {
                   printf(" %-3d  %-20s  %-20s  %-15s  %02d/%02d/%04d  %02d:%02d  %-50s\n",rb,pom->naziv,pom->lokacija,pom->vrsta_dogadjaja,
                          pom->datum.dan,pom->datum.mjesec,pom->datum.godina,pom->datum.sat,pom->datum.minut,
                          pom->opis);

                   printf(" \nKOMENTARI:\n");
                   for(rb=0;rb < pom->koment.broj;rb++)
                   printf("   %s\n",pom->koment.komentar[rb]);
                   printf("\n");
               }


               int Read_File(LISTA *lista)             //Citanje dogadjaja iz fajla
               {
                   lista->head=lista->tail=NULL;

                   FILE *fp=fopen("DOGADJAJ.txt","rb");
                   if(fp == NULL)  return 0;     //datoteka neuspesno otvorena
                   else
                   {
                       DOGADJAJ pom;
                       while(fread(&pom,sizeof(DOGADJAJ),1,fp) == 1)
                        Add_Dj(lista,&pom);
                        fclose(fp);
                   }
                   return 1;
               }



               int Write_File(LISTA *lista)  //upis dogadjaja u fajl
               {
                   FILE *fp=fopen("DOGADJAJ.txt","wb");
                   if(fp == NULL) return 0;
                   else
                   {
                       DOGADJAJ pom;
                       NODE *q=lista->head;
                       while(q != NULL)
                       {
                           pom=q->info;
                           fwrite(&pom,sizeof(DOGADJAJ),1,fp);
                           q=q->right;
                       }
                       fclose(fp);
                   }
                   return 1;
               }





