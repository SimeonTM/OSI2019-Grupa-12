#include "Kviz.h"



          void Read_Quiz(KVIZ *kviz)
          {
              int i;
              char pom[101]={};
              FILE *fp=fopen("Kviz.txt","r");

              if(fp == NULL)  return;

              fscanf(fp,"%d\n",&kviz->length);  //ucitaj broj pitanja

              for(i=0;i<kviz->length;i++)        //citanje kviza oz fajla
              {
                  fscanf(fp,"%s\n",pom);
                  strcpy(kviz->question[i],pom);

                  fscanf(fp,"%s\n",pom);
                  strcpy(kviz->first_answer[i],pom);

                  fscanf(fp,"%s\n",pom);
                  strcpy(kviz->second_answer[i],pom);

                  fscanf(fp,"%s\n",pom);
                  strcpy(kviz->third_answer[i],pom);

                  fscanf(fp,"%d\n",&kviz->correct[i]);
              }
              fclose(fp);
          }



            void Play_Quiz(KVIZ *kviz)
            {
                 printf("\n******DOBRO DOSLI U KVIZ-zabavite se i proverite svoje znanje!!!******\n");
                 int i;
                 int input,counter=0;

                 for(i=0;i<kviz->length;i++)
                 {
                     printf("\n%d.pitanje:%s\n",i+1,kviz->question[i]);
                     printf("  1.odgovor:%s\n",kviz->first_answer[i]);
                     printf("  2.odgovor:%s\n",kviz->second_answer[i]);
                     printf("  3.odgovor:%s\n",kviz->third_answer[i]);


                     do
                     {
                         printf("Vas odgovor je:");
                         scanf("%d",&input);
                     }while(input != 1 && input != 2 && input != 3);

                     if(input == kviz->correct[i])
                     {
                         printf("Pogodili ste!\n");
                         ++counter;
                     }
                     else printf("Tacan odgovor je pod %d.\n",kviz->correct[i]);
                 }

                 printf("\nImali ste %d/%d tacnih odgovora!!!\n",counter,kviz->length);
                 printf("Hvala vam sto ste ucestvovali.\n");
                 printf("**********************************************************************\n");

            }



            void Delete_Question(KVIZ *kviz,int index)
            {
                index-=1;//indeks  pitanja koje se brise u kvizu;
                int last=kviz->length-1;
                if(index != kviz->length-1)  //na mjesto pitanja koje se brise se kopira
                {                            //zadnje pitanje

                    strcpy(kviz->question[index],kviz->question[last]);
                    strcpy(kviz->first_answer[index],kviz->first_answer[last]);
                    strcpy(kviz->second_answer[index],kviz->second_answer[last]);
                    strcpy(kviz->third_answer[index],kviz->third_answer[last]);
                    kviz->correct[index]=kviz->correct[last];

                }

                --kviz->length;     //smanjuje se broj pitanja
            }


            void Add_Question(KVIZ *kviz,const char *question,const char *first_ans,const char *second_ans,const char *third_ans,int correct)
            {
                int index = kviz->length;  //funkcija dodaje novo pitanje u kviz

                strcpy(kviz->question[index],question);
                strcpy(kviz->first_answer[index],first_ans);
                strcpy(kviz->second_answer[index],second_ans);
                strcpy(kviz->third_answer[index],third_ans);
                kviz->correct[index] = correct;

                ++kviz->length;   //povecava se ukupan broj pitanja
            }


             void Write_Quiz(KVIZ *kviz)    //sadrzaj kviza se upisuje u fajl;
             {

              int i;
              FILE *fp=fopen("Kviz.txt","w");
              if(fp == NULL)  return;

              fprintf(fp,"%d\n",kviz->length);  //upis broja pitanja

              for(i=0;i<kviz->length;i++)
              {
                  fprintf(fp,"%s\n",kviz->question[i]);
                  fprintf(fp,"%s\n",kviz->first_answer[i]);
                  fprintf(fp,"%s\n",kviz->second_answer[i]);
                  fprintf(fp,"%s\n",kviz->third_answer[i]);
                  fprintf(fp,"%d\n",kviz->correct[i]);
              }
              fclose(fp);
             }

