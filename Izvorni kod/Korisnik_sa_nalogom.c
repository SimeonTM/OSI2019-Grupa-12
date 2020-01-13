#include "Korisnik_sa_nalogom.h"


                         int Check_Password()
                         {

                         char username[55];
                         char password[55];

                         FILE *fp=fopen("Password.txt","r");
                         if(fp == NULL) return 0;

                         fscanf(fp,"Korisnicko ime:%s\n",username);        //citanje podataka iz fajla
                         fscanf(fp,"Lozinka:%s\n",password);

                         int i;
                         int len1=0,len2=0;
                         char s1[100],s2[100];

                         Footer_Adv();

                         for(i=0;i<3;i++)
                         {
                              printf("\nUnesite vase korisnicko ime:\n");                   //unos korisnickog imena
                              do
                              {
                                  s1[len1] = getch();
                                  if(s1[len1] != '\r') printf("*");
                                  len1++;
                              }while(s1[len1 - 1] != '\r');
                              s1[len1-1] = 0;


                              printf("\nUnesite vasu lozinku:\n");                           //unos lozinke
                              do
                              {
                                  s2[len2] = getch();
                                  if(s2[len2] != '\r') printf("*");
                                  len2++;
                              }while(s2[len2 - 1] != '\r');
                              s2[len2-1]=0;



                              if( !strcmp(s1,username) && !strcmp(s2,password) )
                              {

                                  printf("\nUspjesno ste se prijavili na sistem!");
                                  Footer_Adv();
                                  return 1;
                              }                                                           //korisnik ima tri pokusaja
                                                                                          //da unese validne podatke
                              else printf("\nNe postoji korisnik s tim podacima!");


                         }

                         Footer_Adv();

                         return 0;
                         }




                         void Sort_events(LISTA *events)
                         {
                             Footer_Adv();
                             printf("Odaberite kriterijum za sortiranje dogadjaja:\n");
                             printf("  (1) - prema nazivu                  \n");
                             printf("  (2) - prema lokaciji                \n");
                             printf("  (3) - prema kategoriji              \n");
                             printf("  (4) - prema broju komentara         \n");
                             printf("  (5) - prema duzini opisa dogadjaja  \n");
                             printf("  (6) - prema vremenu odrzavanja      \n\n");

                             char choose;

                             do
                             {
                                 scanf("%c",&choose);            //validacija unesene opcije
                             }while(choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6');

                             if(choose == '1') sortiraj(events,Sort_By_Name);
                             else if(choose == '2') sortiraj(events,Sort_By_Location);
                             else if(choose == '3') sortiraj(events,Sort_By_Category);
                             else if(choose == '4') sortiraj(events,Sort_By_Comments);
                             else if(choose == '5') sortiraj(events,Sort_By_Description);
                             else if(choose == '6') sortiraj(events,Sort_By_Time);

                             printf("\nPodaci uspjesno sortirani!");
                             Footer_Adv();
                         }



                         void Add_New_Category(CATEGORY *src)
                         {
                             Footer_Adv();
                             Print_Catg(*src);

                             printf("\nUnesite naziv nove kategorije:\n");

                             char pom[200];
                             do
                             {
                                 scanf("%s",pom);
                             } while( (Search_Catg(*src,pom) != NULL) || strlen(pom) > 16);         //provera da li postoje dve kategorije sa istim imenom
                                                                                                   //i da li je uneseni naziv prevelik
                             Add_Catg(src,pom);
                             printf("\nUspjesno dodata nova kategorija!");
                             Footer_Adv();

                         }



                         void Delete_Category(CATEGORY *src,LISTA *events)
                         {
                             Footer_Adv();
                             Print_Catg(*src);

                             printf("\nUnesite naziv kategorije koju zelite obrisati:\n");


                             char pom[200];
                             do
                             {
                                 scanf("%s",pom);
                             } while( Search_Catg(*src,pom) == NULL);                 //provera da li postoji kategorija sa tim imenom

                             Delete_Catg(src,pom);
                             printf("\nOdabrana kategorija uspjesno obrisana!\n");
                             Footer_Adv();

                                NODE *q=events->head;
                                while(q != NULL)
                                {
                                    if(strcmp(q->info.vrsta_dogadjaja,pom) == 0)             //brisanje dogadjaja obrisane kategorije
                                    {
                                        NODE *p=q->right;                                    //posto se q oslobadja,treba
                                        Delete_Dj(events,q->info.naziv);                     //sacuvati njegovog desnog susjeda
                                        q=p;
                                    }
                                    else q=q->right;
                                }


                         }


                          void Delete_Event(LISTA *events)
                          {
                              Footer_Adv();
                              printf("Unesite naziv dogadjaja koji zelite obrisati:\n\n");

                              int i;
                              NODE *q;
                              char pom[200];

                              for(i=1,q=events->head;q != NULL;i++,q=q->right)
                                printf(" %d) %s\n",i,q->info.naziv);

                              printf("\n");
                              do
                              {
                                  scanf("%s",pom);
                              }while(Search_Dj(events,pom) == NULL);       //provera da li postoji dogadjaj sa unesenim imenom

                              Delete_Dj(events,pom);

                              printf("\nDogadjaj uspjesno obrisan!\n\n");
                              Footer_Adv();

                          }



                          void Add_New_Event(LISTA *events,CATEGORY *ctg)
                          {
                              Footer_Adv();
                              printf("Unesite parametre novog dogadjaja:\n\n");

                              DOGADJAJ temp;
                              Read_Dj(&temp,*ctg,events);
                              Add_Dj(events,&temp);

                              printf("\n\nDogadjaj uspesno dodat na sistem!");
                              Footer_Adv();
                          }







                          void Change_Event(LISTA *events,CATEGORY *ctg)
                          {
                              Footer_Adv();
                              printf("Unesite naziv dogadjaja koji zelite izmjeniti:\n\n");

                              int i,j,k;
                              NODE *current;
                              char regime;
                              char temp[200];

                              for(i=1,current=events->head; current != NULL; i++,current = current->right)                 //ispis svih dogadjaja
                                printf(" %d) %s\n",i,current->info.naziv);

                              printf("\n");
                              do
                              {
                                  scanf("%s",temp);                                              //provera ucitanog naziva dogadjaja
                              }while( ( current = Search_Dj(events,temp) ) == NULL);

                             printf("Koji parametar dogadjaja zelite promjeniti:\n\n");
                             printf(" 1-naziv\n");
                             printf(" 2-lokacija\n");
                             printf(" 3-opis\n");
                             printf(" 4-kategorija\n");
                             printf(" 5-vreme odrzavanja\n");
                             printf(" 6-komentari\n");
                             printf(" 7-datum odrzavanja\n");

                             do
                             {
                                 scanf("\n%c",&regime);
                             }while(regime !='1' && regime != '2' && regime != '3' && regime != '4' && regime != '5' && regime != '6' && regime != '7');


                             if(regime == '1')
                             {

                                 do                            //izmjena naziva dogadjaja
                                 {

                                     printf("\nUnesite novi naziv dogadjaja:");
                                     scanf("%s",temp);

                                 }while(strlen(temp) > 20 || Search_Dj(events,temp) != NULL);
                                 strcpy(current->info.naziv,temp);

                             }

                             else if(regime == '2')                       //izmjena lokacije dogadjaja
                             {
                                 do
                                 {
                                     printf("\nUnesite novu lokaciju dogadjaja:");
                                     scanf("%s",temp);

                                 }while(strlen(temp) > 20);
                                 strcpy(current->info.lokacija,temp);
                             }

                             else if(regime == '3')                     //izmjena opisa dogadjaja
                             {
                                 do
                                 {
                                       printf("\nUnesite novi opis dogadjaja:");
                                       scanf("%s",temp);
                                 }while(strlen(temp)>50);
                                 strcpy(current->info.opis,temp);
                             }


                             else if(regime == '4')
                             {                                                          //izmjena kategorije dogadjaja
                                  do
                                  {
                                     Print_Catg(*ctg);
                                     printf("\nUnesite redni broj zeljene kategorije:");
                                     scanf("%d",&i);
                                 }while(i<1 || i>ctg->length);
                                 strcpy(current->info.vrsta_dogadjaja,ctg->niz[i-1]);
                             }


                             else if(regime == '5')
                             {
                                 do                                                     //izmjena kategorije dogadjaja
                                 {
                                      printf("\nUnesite sat i minutu odrzavanja:\n");
                                      printf("\nSat:");        scanf("%d",&i);
                                      printf("\nMinuta:");     scanf("%d",&j);
                                 }while(i<0 || i>23 || j<0 || j>59);                                   //validacija minuta i sekundi
                                 current->info.datum.sat=i;          current->info.datum.minut=j;
                             }


                             else if(regime == '6')                          //izmjena komentara dogadjaja
                             {
                                     do
                                     {
                                           printf("\nUnesite komentar za dati dogadjaj:");
                                           scanf("%s",temp);
                                     }while(strlen(temp) > 50);
                                     current->info.koment.broj=1;
                                     strcpy(current->info.koment.komentar[0],temp);
                             }

                             else
                             {
                                    do
                                    {                                                                                                 //izmjena datuma dogadjaja
                                           printf("\nUnesite novu godinu desavanja:");          scanf("%d",&i);
                                           printf("\nUnesite novi mjesec desavanja:");          scanf("%d",&j);
                                           printf("\nUnesite novi dan desavanja:");             scanf("%d",&k);
                                    }while(i<0 || i>9999 || j<1 || j>12 || k<1 || k>31);             //validacija godine i mjeseca

                                    current->info.datum.godina=i;        current->info.datum.mjesec=j;     current->info.datum.dan=k;
                             }

                             printf("\n\nIzmjene uspjesno sacuvane!");
                             Footer_Adv();

                          }


                         void Footer_Adv()
                         {
                             printf("\n\n************************************************\n\n");
                         }







                         void Change_Quiz()
                         {
                             KVIZ kviz;
                             char flag;
                             Read_Quiz(&kviz);

                             Footer_Adv();
                             printf("Da li zelite dodati novo pitanje-(1) ili obrisati postojece-(2) ?\n");

                             do
                             {
                                  scanf("\n%c",&flag);
                             }while(flag != '1' && flag != '2');


                             if(flag == '1')
                             {
                                 if(kviz.length == 10)
                                 {
                                     printf("Svih 10 pitanja je vec popunjeno(da biste dodali novo izbrisite neko od postojecih)!");
                                     Footer_Adv();
                                     return;
                                 }

                                 char temp[101];                           //unos elemenata pitanja
                                 int current=kviz.length;
                                 kviz.length+=1;

                                 printf("Unesite tekst pitanja:\n");
                                 do
                                 {
                                     scanf("%s",temp);
                                 }while(strlen(temp) > 100);
                                 strcpy(kviz.question[current],temp);


                                  printf("Unesite 1. opciju:\n");
                                   do
                                   {
                                         scanf("%s",temp);
                                   }while(strlen(temp) > 25);
                                   strcpy(kviz.first_answer[current],temp);

                                   printf("Unesite 2. opciju:\n");
                                   do
                                   {
                                         scanf("%s",temp);
                                   }while(strlen(temp) > 25);
                                   strcpy(kviz.second_answer[current],temp);


                                   printf("Unesite 3. opciju:\n");
                                   do
                                   {
                                         scanf("%s",temp);
                                   }while(strlen(temp) > 25);
                                   strcpy(kviz.third_answer[current],temp);

                                   printf("Unesite redni broj tacne opcije:\n");
                                   do
                                   {
                                       scanf("%c",&flag);
                                   }while(flag != '1' && flag != '2' && flag != '3');

                                   kviz.correct[current]=flag-48;
                                   printf("\nUneseno pitanje uspjesno dodato!\n");
                                   Footer_Adv();
                                 }

                                 else
                                 {
                                     int i;

                                     printf("Spisak pitanja:\n\n");
                                     for(i=0;i<kviz.length;i++)
                                        printf(" %d - %s\n",i+1,kviz.question[i]);

                                     printf("\nUnesite redni broj pitanja za brisanje:\n\n");

                                     do
                                     {
                                         scanf("%d",&i);
                                     }while( i<1 || i > (kviz.length+1) );

                                     Delete_Question(&kviz,i);
                                     printf("\n\nOdabrano pitanje uspjesno obrisano!");
                                     Footer_Adv();
                                 }
                                 Write_Quiz(&kviz);
                             }






                             void Change_City()
                             {
                                 CITY grad;
                                 Read_City(&grad);

                                 Footer_Adv();
                                 Print_City(&grad);

                                 printf("\n\nKoji parametar grada zelite promenite:\n\n");
                                 printf(" 1-naziv        \n");
                                 printf(" 2-populacija   \n");
                                 printf(" 3-drzava       \n");
                                 printf(" 4-lokacija     \n");
                                 printf(" 5-naselja      \n");
                                 printf(" 6-znamenitosti \n\n");

                                 char regime;
                                 char temp[200];
                                 int i;

                                 do                    //validacija unesene opcije
                                 {
                                     scanf("%c",&regime);
                                 }while(regime != '1' && regime != '2' && regime != '3' && regime != '4' && regime != '5' && regime != '6');

                                 printf("\n\n");

                                 if(regime == '1')                      //promjena naziva grada
                                 {
                                     printf("Unesite novi naziv grada:\n");
                                     do
                                     {
                                         scanf("%s",temp);
                                     }while(strlen(temp) > 32);
                                     strcpy(grad.naziv,temp);

                                     printf("Koji je nadimak ili pseudonim karakteristacan za taj grad?\n");
                                     do
                                     {
                                         scanf("%s",temp);
                                     }while(strlen(temp) > 32);
                                     strcpy(grad.pseudonim,temp);
                                 }

                                 else if(regime == '2')                       //promjena broja stanovnika
                                 {
                                     printf("Unesite broj stanovnika:\n");
                                     do
                                     {
                                         scanf("%d",&i);
                                     }while(i <= 0);
                                     grad.populacija = i;
                                 }

                                 else if(regime == '3')                         //promjena drzave
                                 {
                                     printf("Unesite naziv drzave u kojoj se grad nalazi:\n");
                                     do
                                     {
                                         scanf("%s",temp);
                                     }while(strlen(temp) > 32);
                                     strcpy(grad.drzava,temp);
                                 }

                                 else if(regime == '4')                            //promjena lokacije u kojoj se grad nalazi
                                 {
                                     printf("Unesite lokaciju grada:\n");
                                     do
                                     {
                                         scanf("%s",temp);
                                     }while(strlen(temp) > 32);
                                     strcpy(grad.lokacija,temp);
                                 }

                                 else if(regime == '5')                 //promjena naselja grada
                                 {
                                     printf("Unesite broj naselja:\n");
                                     do
                                     {
                                         scanf("%d",&i);
                                     }while(i < 0 || i > 6);
                                     grad.naselja.current = i;

                                     for(i=0;i < grad.naselja.current;i++)
                                     {
                                         printf("\nUnesite naziv %d. naselja:",i+1);
                                         do
                                         {
                                              scanf("%s",temp);
                                         }while(strlen(temp) > 32);
                                         strcpy(grad.naselja.niz[i],temp);
                                     }

                                 }


                                 else
                                 {
                                     printf("Unesite broj znamenitosti:\n");            //promjena znamenitosti grada
                                     do
                                     {
                                         scanf("%d",&i);
                                     }while(i < 0 || i > 6);
                                     grad.znamenitosti.current = i;

                                     for(i=0;i < grad.znamenitosti.current;i++)
                                     {
                                         printf("\nUnesite naziv %d. znamenitosti:",i+1);
                                         do
                                         {
                                              scanf("%s",temp);
                                         }while(strlen(temp) > 32);
                                         strcpy(grad.znamenitosti.niz[i],temp);
                                     }
                                 }

                                 printf("\nIzmjene uspjesno sacuvane!");
                                 Footer_Adv();

                                 Write_City(&grad);   //ipis grada u fajl
                             }





                             void Print_Menu_Advanced()
                             {
                                 Print_Menu();
                                 printf("|                                DODAVANJE NOVOG DOGADJAJA(10)                        BRISANJE DOGADJAJA(11)                    IZMJENA DOGADJAJA(12)                                           |\n");
                                 printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                 printf("|     SORTIRANJE DOGADJAJA(13)                                                        IZMJENA KVIZA(14)                                                          IZMJENA PARAMETARA GRADA(15)   |\n");
                                 printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                 printf("|                                      DODAVANJE KATEGORIJE DOGADJAJA(16)                                              BRISANJE KATEGORIJE DOGADJAJA(17)                                        |\n");
                                 printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
                             }




