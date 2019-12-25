#include "Kategorija.h"



                       CATEGORY Read_Catg_File()  //ucitavanje kategorija iz fajla
                       {
                            CATEGORY rez;
                            rez.niz=NULL;

                            FILE *fp=fopen("KATEGORIJA.txt","r");

                            if(fp != NULL)
                            {
                                int q,i;
                                char pom[100];

                                fscanf(fp,"%d\n",&q);       //ucitava se broj kategorija
                                rez.length=q;
                                rez.niz = (char **)calloc(rez.length,sizeof(char*));

                                for(i=0;i<rez.length;i++)
                                {
                                    fscanf(fp,"%s\n",pom);
                                    rez.niz[i]=(char *)calloc(strlen(pom),sizeof(char));
                                    strcpy(rez.niz[i],pom);
                                }
                                fclose(fp);
                            }

                            return rez;
                      }



                      void Print_Catg(CATEGORY src)
                      {
                          if(src.niz == NULL)  return;
                          int i;
                          printf("Kategorije dogadjaja:\n");     //formatirani upis kategorija
                          for(i=0;i < src.length;i++)
                            printf(" %d %s\n",i+1,src.niz[i]);
                      }



                     char* Search_Catg(CATEGORY src,const char *key)
                     {
                         int i;                           //proverava se da li postoji neka kategorija
                         for(i=0;i<src.length;i++)
                            if(!strcmp(src.niz[i],key))
                            return src.niz[i];

                         return NULL;
                     }


                     void Write_Catg_File(CATEGORY src)        //upis kategorija u fajl
                     {
                         FILE *fp=fopen("KATEGORIJA.txt","w");

                         if(fp != NULL)
                         {
                             int i;
                             fprintf(fp,"%d\n",src.length);
                             for(i=0;i<src.length;i++)
                                fprintf(fp,"%s\n",src.niz[i]);
                             fclose(fp);
                         }
                     }



                          void Delete_Catg_Arr(CATEGORY  *src)
                          {
                              int i;
                              for(i=0;i<src->length;i++)    //oslobadjanje memorije
                                free(src->niz[i]);
                              free(src->niz);
                              src->niz=NULL;
                          }



                          void Add_Catg(CATEGORY *src,const char *value)
                          {
                              if(src->length > 0)                                                         //ako matrica nije prazna
                              {
                                   src->length+=1;
                                   src->niz=(char**)realloc(src->niz , sizeof(char*) * (src->length) );   //realocira se niz pokazivaca na stringove
                                   src->niz[src->length-1] = (char *)malloc(16*sizeof(char));              //i povecava se za 1
                                   strcpy(src->niz[src->length-1],value);
                              }

                              else                                                                          //ako je matrica  prazna
                              {
                                  src->length+=1;
                                  src->niz=(char**)malloc(sizeof(char*));
                                  src->niz[0]=(char *)malloc(16*sizeof(char));
                                  strcpy(src->niz[0],value);
                              }
                          }


                          void Delete_Catg(CATEGORY *src,const char *key)
                          {
                              char *pom=Search_Catg(*src,key);         //trazi se lokacija u matrici
                              if(pom == NULL)  return;                 //na mesto sringa koji se brise kopira se zadnji string iz matrice
                              if(pom != src->niz[src->length-1])
                              strcpy(pom,src->niz[src->length-1]);

                              char **temp=(char**)calloc(src->length-1,sizeof(char*));
                              int i;
                              for(i=0;i < src->length-1;i++)
                              temp[i]=src->niz[i];

                              free(src->niz[src->length-1]);         //oslobadja se string koji se zeli obrisati
                              free(src->niz);
                              src->length-=1;                          //broj kategorija se smanjuje za 1
                              src->niz=temp;

                          }




