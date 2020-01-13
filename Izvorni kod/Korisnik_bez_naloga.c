#include "Korisnik_bez_naloga.h"

void Print_All_Events(LISTA *lista)
{
    printf("\n\n");
    Footer();
    Header();
    Footer();

    NODE *q = lista->head;
    int i=1;

    for(;q != NULL;q=q->right,++i)
    Write_Dj(&(q->info),i);

    Footer();
    printf("\n\n");

}

void Quiz()
{
    KVIZ temp;
    Read_Quiz(&temp);

    printf("\n\n");
    Play_Quiz(&temp);
    printf("\n\n");
}



void Print_Events_By_Category(LISTA *lista,CATEGORY kategorija)
{
    printf("\n\n******************************\n");
    printf("Odaberite neku od katogorija:\n");
    Print_Catg(kategorija);
    int rb;
    do
    {
        scanf("%d",&rb);                            //proverava se da li je
    }while(rb < 1 || rb > kategorija.length );         //unesen validan redni broj
    printf("******************************\n");

    const char *key= kategorija.niz[rb-1];            //pointer na naziv katogorije

    printf("\n");
    Footer();
    Header();
    Footer();

    NODE *q = lista->head;
    int i=1;

    for(;q != NULL ; q=q->right,++i)  //provera vrste dogadjaja
    if(!strcmp(q->info.vrsta_dogadjaja,key))
    Write_Dj(&(q->info),i);

    Footer();
    printf("\n\n");                                                   //kategorije
}


void Print_Front_Page(const char *fajl)
{
    FILE *fp=fopen(fajl,"r");
    if(fp == NULL)  return;

    char temp;
    while( (temp = getc(fp)) != EOF )
    printf("%c",temp);

    printf("\n\n");
}


void Add_Comment_To_Event(LISTA *lista)
{
    printf("\n\n******************************\n");
    printf("Unesite naziv dogadjaja:\n");
    int i=0;
    NODE *q=lista->head;
    char flag[200];

    for(;q != NULL;q=q->right)
    {
      printf(" %d) %s\n",++i,q->info.naziv);      //ispis naziva dogadjaja
    }

    do
    {   scanf("%s",flag);   }
    while( (q = Search_Dj(lista,flag)) == NULL);

    printf("Unesite svoj komentar:\n");

   do
   {
       scanf("%s",flag);                  //provera duzine unesenog komentara
   }while(strlen(flag) > 51);


   if(q->info.koment.broj == 3) q->info.koment.broj=1;
   else ++q->info.koment.broj;
   strcpy(q->info.koment.komentar[q->info.koment.broj-1],flag);

   printf("Komentar uspjesno dodan!\n");

   printf("\n\n");
                                                        //ako su popunjena sva tri komentara
}                                                         //svi komentari se resetuju,a novi upisuje u prvo polje



 void Print_Events_By_Time(LISTA *lista,int rezim)
 {

    int godina,mjesec,dan;
    NODE *q=lista->head;
    int brojac=0;

    time_t trenutno_vreme;
    time(&trenutno_vreme);
    struct tm *datum = localtime(&trenutno_vreme);
    dan=datum->tm_mday;
    godina=datum->tm_year+1900;
    mjesec=datum->tm_mon+1;

    printf("\n\n");
    Footer();
    Header();
    Footer();

    if(rezim == 0)              //pisu se danasnji dogadjaji
    {
        for(;q != NULL;q=q->right)
            if(q->info.datum.godina == godina && q->info.datum.mjesec == mjesec && q->info.datum.dan == dan)
            Write_Dj(&q->info,++brojac);
    }

    else if(rezim == 1)        //pisu se buduci dogadjaji
    {
        for(;q != NULL;q=q->right)
            if( (q->info.datum.godina > godina) || (q->info.datum.godina == godina && q->info.datum.mjesec > mjesec)
            || (q->info.datum.godina == godina && q->info.datum.mjesec == mjesec && q->info.datum.dan > dan) )
            Write_Dj(&q->info,++brojac);
    }

    else if(rezim == -1)
    {
        for(;q != NULL;q=q->right)
            if( (q->info.datum.godina < godina) || (q->info.datum.godina == godina && q->info.datum.mjesec < mjesec)
            || (q->info.datum.godina == godina && q->info.datum.mjesec == mjesec && q->info.datum.dan < dan) )
            Write_Dj(&q->info,++brojac);
    }



    Footer();
    printf("\n\n");
 }


void Print_City_User()
{
    CITY src;
    Read_City(&src);
    Print_City(&src);
}

void Print_Menu()
{
    printf("-----------------------------------------------\n");
    printf("|    (1) PREGLED DANASNJIH DOGADJAJA          |\n");
    printf("|    (2) PREGLED PROTEKLIH DOGADJAJA          |\n");
    printf("|    (3) PREGLED BUDUCIH DOGADJAJA            |\n");
    printf("|    (4) IGRANJE KVIZA                        |\n");
    printf("|    (5) KOMENTARISANJE                       |\n");
    printf("|    (6) PREGLED GRADA                        |\n");
    printf("|    (7) PREGLED DOGADJAJA PREMA KATEGORIJI   |\n");
    printf("|    (8) PREGLED SVIH DOGADJAJA               |\n");
    printf("|    (9) NESTO O AUTORIMA                     |\n");
    printf("|    (#) KRAJ                                 |\n");
    printf("-----------------------------------------------\n");
    printf(" Unesi broj opcije : ");
}
