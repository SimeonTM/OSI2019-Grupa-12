#include "Grad.h"

           void Read_City(CITY *grad)
          {
              FILE *fp=fopen("Grad.txt","r");
              if(fp== NULL) return;

              int i;

              fscanf(fp,"%s\n",grad->naziv);
              fscanf(fp,"%s\n",grad->pseudonim);
              fscanf(fp,"%d\n",&grad->populacija);
              fscanf(fp,"%s\n",grad->drzava);
              fscanf(fp,"%s\n",grad->lokacija);

              fscanf(fp,"%d\n",&grad->naselja.current);   //ucitavanja broja naselja
              for(i=0;i<grad->naselja.current;i++)
                  fscanf(fp,"%s\n",grad->naselja.niz[i]);



              fscanf(fp,"%d\n",&grad->znamenitosti.current);   //ucitavanje broja znamenitosti
              for(i=0;i<grad->znamenitosti.current;i++)
              fscanf(fp,"%s\n",grad->znamenitosti.niz[i]);

              fclose(fp);

          }



                void Print_City(CITY *city)
                {
                    int i;                                 //ispis grada na konzolu

                    printf("\n\n");
                    printf("*******************************************************\n");
                    printf("Naziv grada: %s -  %s\n",city->naziv,city->pseudonim);
                    printf("Broj stanovnika : %d\n",city->populacija);
                    printf("Drzava : %s\n",city->drzava);
                    printf("Lokacija : %s\n",city->lokacija);

                    printf("Naselja : \n");
                    for(i=0;i<city->naselja.current;i++)
                        printf("     %s\n",city->naselja.niz[i]);

                    printf("Znamenitosti:\n");
                    for(i=0;i<city->znamenitosti.current;i++)
                        printf("     %s\n",city->znamenitosti.niz[i]);

                    printf("*******************************************************\n\n");

                }


                void Write_City(CITY *grad)
                {

                FILE *fp=fopen("Grad.txt","w");
                if(fp== NULL) return;

                int i;

                fprintf(fp,"%s\n",grad->naziv);
                fprintf(fp,"%s\n",grad->pseudonim);
                fprintf(fp,"%d\n",grad->populacija);
                fprintf(fp,"%s\n",grad->drzava);
                fprintf(fp,"%s\n",grad->lokacija);

                fprintf(fp,"%d\n",grad->naselja.current);
                for(i=0;i<grad->naselja.current;i++)
                fprintf(fp,"%s\n",grad->naselja.niz[i]);

                fprintf(fp,"%d\n",grad->znamenitosti.current);
                for(i=0;i<grad->znamenitosti.current;i++)
                fprintf(fp,"%s\n",grad->znamenitosti.niz[i]);

                fclose(fp);
                }
