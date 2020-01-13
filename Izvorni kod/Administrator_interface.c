#include "Korisnik_bez_naloga.h"
#include "Korisnik_sa_nalogom.h"


             int main()
             {
                  LISTA events;
                  Read_File(&events);

                  CATEGORY categories=Read_Catg_File();
                  char regime[50];
                  int flag=0;
                  int password=0;


                  do
                  {
                       Print_Front_Page("Naslovna.txt");       //odabir funkcije sistema
                       Print_Menu_Advanced();

                       scanf("%s",regime);

                       if(!strcmp(regime,"1"))
                        Print_Events_By_Time(&events,0);

                       else if(!strcmp(regime,"2"))
                        Print_Events_By_Time(&events,-1);

                       else if(!strcmp(regime,"3"))
                        Print_Events_By_Time(&events,1);

                       else if(!strcmp(regime,"4"))
                        Quiz();

                       else if(!strcmp(regime,"5"))
                       {
                            Add_Comment_To_Event(&events);
                            ++flag;
                       }


                       else if(!strcmp(regime,"6"))                     //funkcije koje su dostupne bez prijave na sistem
                        Print_City_User();

                       else if(!strcmp(regime,"7"))
                        Print_Events_By_Category(&events,categories);

                        else if(!strcmp(regime,"8"))
                            Print_All_Events(&events);

                        else if(!strcmp(regime,"9"))
                             Print_Front_Page("Autori.txt");

                        else if(strcmp(regime,"10") && strcmp(regime,"11") && strcmp(regime,"12") && strcmp(regime,"13") && strcmp(regime,"14") && strcmp(regime,"15") && strcmp(regime,"16") && strcmp(regime,"17"))
                        {
                           if(strcmp(regime,"#"))   printf("Nepoznata opcija!\n");
                        }


                        else
                        {
                            if(password == 0) password = Check_Password();
                            else                                                                 //da bi se pristupilo ovom delu korisnik se mora prijaviti na sistem
                            {
                                ++flag;

                                if(!strcmp(regime,"10"))
                                    Add_New_Event(&events,&categories);

                                else if(!strcmp(regime,"11"))
                                    Delete_Event(&events);

                                else if(!strcmp(regime,"12"))
                                    Change_Event(&events,&categories);

                                else if(!strcmp(regime,"13"))
                                    Sort_events(&events);

                                else if(!strcmp(regime,"14"))
                                     Change_Quiz();

                                else if(!strcmp(regime,"15"))
                                     Change_City();

                                else if(!strcmp(regime,"16"))
                                     Add_New_Category(&categories);

                                else if(!strcmp(regime,"17"))
                                     Delete_Category(&categories,&events);
                            }

                        }

                       getch();                //enter
                       system("cls");          //osvjezavanje konzole

                  }while(strcmp(regime,"#"));

                  if(flag > 0)  Write_File(&events);           //ako su vrsene izmjene nad dogadjajima ,upisuju se u fajl
                  Write_Catg_File(categories);

                  Delete_List(&events);
                  Delete_Catg_Arr(&categories);

                  printf("Hvala vam za vasu posjetu i dodjite nam opet!");
                  getch();

                  return 0;

             }
