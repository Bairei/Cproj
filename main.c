#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "init_zesp.h"
#include "init_alb.h"
#include "akcja.h"
#include "struct_los.h"
void search (list_band *first,list_alb *alb_first)
{

        char fraza[35]="0";
        //int i;
        while(strcmp("0",fraza)==0)
            {
            printf("wpisz fraze (np. imie i/lub nazwisko, nazwa albumu/zespolu, nazwa wydawcy albumu):\n");
            //scanf("%34s",fraza); DZIALA DLA FRAZ JEDNOWYRAZOWYCH
            fflush(stdin);
            fflush(stdout);
            scanf ("%34[^\n]", fraza);
                if(strcmp("0",fraza)==0)
                {
                    system("cls");
                    printf("Podano nieprawidlowa fraze!\n\n");
                }
            }
            szukajfraz(fraza,first,alb_first);
}

void add(list_band *first,list_alb *alb_first)
{
    char wybor2[9];

    printf("wybierz, do ktorej bazy chcesz dodac rekord:\n1)zespoly\n2)albumy\n");
    while(strcmp(wybor2,"1")!=0||strcmp(wybor2,"2")!=0)
    {
    fflush(stdin);
    fflush(stdout);
    scanf("%10[^\n]%*c",wybor2);

    if(strcmp(wybor2,"1")==0)
    {
        addzesp (first);
        break;
    }
    else if(strcmp(wybor2,"2")==0)
    {
        addalb (alb_first);
        break;
    }
    else printf("podano bledne wyrazenie\n");
    }

    system("pause");
    system ("cls");

}

void usun(list_band *first,list_alb *alb_first)
{
    char wybor2[3];

    printf("wybierz, z ktorej bazy chcesz usunac rekord:\n1)zespoly\n2)albumy\n");
    while(strcmp(wybor2,"1")!=0||strcmp(wybor2,"2")!=0)
    {
    fflush(stdin);
    fflush(stdout);
    scanf("%2[^\n]%*c",wybor2);

    if(strcmp(wybor2,"1")==0)
    {
        usunzesp (first);
        break;
    }
    else if(strcmp(wybor2,"2")==0)
    {
        usunalb (alb_first);
        break;
    }
    else printf("podano bledne wyrazenie\n");
    }
}

void losuj(list_band *first, list_alb *alb_first,list_los *los_first)
{
    srand(time(NULL));
    int i=0;
    char wybierzlos[4]="45";
    char gat[35];
    int w=0;
    //int przes;
    list_band *losband = first;
    list_alb *losalb = alb_first;
    list_los *wyn_band= los_first;
    list_los *wyn_alb= los_first;
    //list_los *wyn_nowy;

    while(strcmp(wybierzlos,"1")!=0&&strcmp(wybierzlos,"2")!=0)
    {
    printf("\n wybierz, na ktorej bazie mam losowac rekomendacje:\n1)zespoly\n2)albumy\n");
    scanf("%3s",wybierzlos);
    }

    printf("\npodaj gatunek muzyczny:\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%34[^\n]%*c",gat);

    if(strcmp(wybierzlos,"1")==0)
    {

        //while(losband->prev!=NULL) losband=losband->prev;


        while(losband!=NULL)
    {
        while(i==0)
            {
            if (strcasestr(losband->gat1,gat)!=NULL||strcasestr(losband->gat2,gat)!=NULL)
            {
                i=1;
                list_los *wyn_nowy=calloc(1,sizeof(list_los));
                wyn_nowy->nazwa_zesp=losband->nazwa;
                wyn_band=wyn_nowy;
            }
            losband=losband->next;

            }
        if(strcasestr(losband->gat1,gat)!=NULL||strcasestr(losband->gat2,gat)!=NULL)
        {

            list_los *wyn_nowy=calloc(1,sizeof(list_los));
            wyn_nowy->nazwa_zesp=losband->nazwa;
            wyn_nowy->next=NULL;
            wyn_band->next=wyn_nowy;
            wyn_nowy->prev=wyn_band;
            if(losband->next!=NULL) wyn_band=wyn_band->next;
        }
        losband=losband->next;
    }


    while(wyn_band->prev!=NULL)
        {
            wyn_band=wyn_band->prev;
        }

    while(wyn_band!=NULL)
        {

            if(wyn_band->next==NULL)
            {
                printf("proponowany zespol:%s\n",wyn_band->nazwa_zesp);
                break;
            }
            else
            {
                w=rand()%10+1;
               // printf("%d",w);
                if(w==10)
                {
                    printf("\nproponowany zespol:%s\n",wyn_band->nazwa_zesp);
                    break;
                }
                else wyn_band=wyn_band->next;
             }
        }
    }

    if(strcmp(wybierzlos,"2")==0)
    {
        while(losalb!=NULL)
        {
            while(i==0)
            {
                if(strcasestr(losalb->gat1,gat)!=NULL||strcasestr(losalb->gat2,gat)!=NULL)
                {
                    i=1;
                    list_los *wyn_nowy=calloc(1,sizeof(list_los));
                    wyn_nowy->nazwa_alb=losalb->nazwa_alb;
                    wyn_nowy->nazwa_zesp=losalb->nazwa_zesp;
                    wyn_alb = wyn_nowy;
                }
                losalb=losalb->next;
            }

            if(strcasestr(losalb->gat1,gat)!=NULL||strcasestr(losalb->gat2,gat)!=NULL)
            {
                list_los *wyn_nowy = calloc(1,sizeof(list_los));
                wyn_nowy->nazwa_alb=losalb->nazwa_alb;
                wyn_nowy->nazwa_zesp=losalb->nazwa_zesp;
                wyn_nowy->next=NULL;
                wyn_alb->next=wyn_nowy;
                wyn_nowy->prev=wyn_alb;
                wyn_alb=wyn_alb->next;
            }
            losalb=losalb->next;
        }

        while(wyn_alb->prev!=NULL) wyn_alb=wyn_alb->prev;

        while(wyn_alb!=NULL)
        {
            if(wyn_alb->next==NULL)
            {
                printf("\nsugerowany album: %s, autorstwa zespolu %s\n",wyn_alb->nazwa_alb,wyn_alb->nazwa_zesp);
                break;
            }
            else
            {
                w=rand()%10+1;
              //  printf("%d",w);
                if(w==10)
                {
                    printf("\nsugerowany album:%s, autorstwa zespolu %s\n", wyn_alb->nazwa_alb,wyn_alb->nazwa_zesp);
                    break;
                }
                else wyn_alb=wyn_alb->next;
            }

        }


    }

    system("pause");
    system("cls");
}

void wydruk(list_band *first, list_alb *alb_first)
{
    list_band *band = first;
    list_alb *alb = alb_first;
    char baza[5] = "-1";

    while(strcmp("1",baza)!=0&&strcmp("2",baza)!=0)
    {
        printf("\nwybierz, z ktorej bazy chcesz zobaczy liste WSZYSTKICH rekordow:\n1 - zespoly\n2 - albumy\n0-anuluj operacje\n");
        scanf("%3s", baza);
        printf("%s",baza);
        if(strcmp(baza,"1")!=0&&strcmp(baza,"2")!=0&&strcmp(baza,"0")!=0)
        {
        system("cls");
        printf("\npodano nieprawidlowa liczbe!!!\n");
        }

        if(strcmp(baza,"0")==0) break;
    }

    if (strcmp(baza,"1")==0)
    {
        while(band!=NULL)
        {
            printf("\nzespol:%s, zalozony w roku %d,",band->nazwa,band->rok_zal);
            if(band->koniec_dzial<=2016&&band->koniec_dzial>=band->rok_zal) printf("zakonczyl dzialalnosc w roku %d\n",band->koniec_dzial);
            else printf("aktywny do dnia dzisiejszego\n");

            printf("czlonkowie: %s, %s", band->cz1,band->cz2);
            if(strcmp(band->cz3,"0")!=0) printf(", %s",band->cz3);
            if(strcmp(band->cz4,"0")!=0) printf(", %s",band->cz4);
            if(strcmp(band->cz5,"0")!=0) printf(", %s",band->cz5);
            if(strcmp(band->cz6,"0")!=0) printf(", %s",band->cz6);
            if(strcmp(band->cz7,"0")!=0) printf(", %s",band->cz7);
            if(strcmp(band->cz8,"0")!=0) printf(", %s",band->cz8);
            if(strcmp(band->cz9,"0")!=0) printf(", %s",band->cz9);
            printf("\ngatunki muzyczne, ktore zespol wykonuje: %s, %s\n\n",band->gat1,band->gat2);

            band=band->next;
        }
    }

    else if (strcmp(baza,"2")==0)
    {
        while(alb!=NULL)
        {
            printf("\nalbum: %s, nagrany przez zespol %s i wydany w roku %d\n",alb->nazwa_alb,alb->nazwa_zesp,alb->rok_wyd);
            printf("czlokowie, ktorzy brali udzial przy nagraniu albumu:\n%s, %s",alb->cz1,alb->cz2);
            if(strcmp(alb->cz3,"0")!=0) printf(", %s",alb->cz3);
            if(strcmp(alb->cz4,"0")!=0) printf(", %s",alb->cz4);
            if(strcmp(alb->cz5,"0")!=0) printf(", %s",alb->cz5);
            if(strcmp(alb->cz6,"0")!=0) printf(", %s",alb->cz6);
            if(strcmp(alb->cz7,"0")!=0) printf(", %s",alb->cz7);
            if(strcmp(alb->cz8,"0")!=0) printf(", %s",alb->cz8);
            if(strcmp(alb->cz9,"0")!=0) printf(", %s",alb->cz9);

            printf("\nproducent: %s, wydawca: %s,\ngatunki muzyczne, ktore wystepuja na danym albumie: %s, %s\n\n",alb->prod,alb->wyd,alb->gat1,alb->gat2);

            alb=alb->next;

        }
    }

    if(strcmp(baza,"0")!=0 && (strcmp(baza,"1")==0||strcmp(baza,"2")==0)) system("pause");

    system("cls");

}




int main()
{
   /* list_band *first = malloc (sizeof(list_band));
    list_alb *alb_first = malloc(sizeof(list_alb));
    alb_first->next=NULL;
    alb_first->prev=NULL;
    first->next=NULL;
    first->prev=NULL;
    first = init_zesp(first);
    alb_first = init_alb(alb_first);*/

    printf("Witaj!\n");

    while (1)
    {
    char opcja[11]="-32498";
    list_band *first = NULL;
    list_alb *alb_first = (list_band*) malloc(sizeof(list_alb));
    list_los *los_first = (list_los*)malloc(sizeof(list_los));
    los_first->next=NULL;
    los_first->prev=NULL;
    alb_first->next=NULL;
    alb_first->prev=NULL;
    /* first->next=NULL;
    first->prev=NULL; */
    first = init_zesp(first);
    alb_first = init_alb(alb_first);


        printf("prosze wybrac opcje:\n1)wyszukiwanie rekordu\n2)dodawanie rekordu\n3)usuwanie rekordu\n4)losowanie sugerowanego przez program zespolu\n5) Spis zespolow/albumow z lat xx-tych\n");
        printf("6)edycja rekordu\n7)wypisanie wszystkich rekordow z wybranej bazy\n0) wyjscie\n");
        fflush(stdin);
        fflush(stdout);
        scanf ("%10s", opcja);

        /*if(strcmp(opcja,"-32498")==0)
        {
        printf("BLAD PROGRAMU, NASTAPI AWARYJNE WYJSCIE");
        abort();
        }*/

        if (strcmp(opcja,"1")==0) search(first,alb_first);

        else if (strcmp(opcja,"2")==0) add(first,alb_first);

        else if (strcmp(opcja,"3")==0) usun(first,alb_first);

        else if (strcmp(opcja,"4")==0) losuj(first,alb_first,los_first);

        else if (strcmp(opcja,"5")==0) zlat(first,alb_first);

        else if (strcmp(opcja,"6")==0) edyt(first,alb_first);

        else if (strcmp(opcja,"7")==0) wydruk (first,alb_first);

        else if (strcmp(opcja,"0")==0) break;

        else
        {
        system("cls");
        printf("prosze podac cyfre podana przy wybranej przez ciebie komendzie!\n\n");
        }


    }

    return 0;
}
