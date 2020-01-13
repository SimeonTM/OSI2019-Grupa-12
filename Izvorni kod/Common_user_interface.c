#include "Korisnik_bez_naloga.h"
#include "Grad.h"
#include <conio.h>

int main()
{
    LISTA events;
    Read_File(&events);

    CATEGORY categories=Read_Catg_File();
    char regime;
    int flag=0;                               //odabir funkcije sistema

    do
    {
        Print_Front_Page("Naslovna.txt");
        Print_Menu();
        printf(" Unesi broj opcije : ");

        scanf("\n%c",&regime);
        switch(regime)
        {   case '1':   Print_Events_By_Time(&events,0);    break;
            case '2':   Print_Events_By_Time(&events,-1);   break;
            case '3':   Print_Events_By_Time(&events,1);    break;
            case '4':   Quiz();                             break;
            case '5':   Add_Comment_To_Event(&events); ++flag;          break;
            case '6':   Print_City_User();                              break;
            case '7':   Print_Events_By_Category(&events,categories);   break;
            case '8':   Print_All_Events(&events);          break;
            case '9':   Print_Front_Page("Autori.txt");     break;
            case '#':                                       break;
            default :   printf("Nepoznata opcija!\n");
        }
        getch();                //enter
        system("cls");          //osvjezavanje konzole

    }while(regime != '#');

    if(flag > 0)
    Write_File(&events);

    Delete_List(&events);
    Delete_Catg_Arr(&categories);

    printf("Hvala vam za vasu posjetu i dodjite nam opet!");
    getch();

    return 0;

}
