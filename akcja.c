#include "akcja.h"
#include <limits.h>

char *strcasestr(const char *zrodlo, const char *fragment)
{
int i;
int matchamt=0;

	for(i=0;i<zrodlo[i];i++)
	{
		if (tolower(zrodlo[i]) != tolower(fragment[matchamt]))
		{
			matchamt = 0;
		}
		if (tolower(zrodlo[i]) == tolower(fragment[matchamt]))
		{
			matchamt++;
			if (fragment[matchamt]==0) return (char *)1;
		}
	}

	return 0;
}

void szukajfraz(char *fraza, list_band *first, list_alb *alb_first)
{
    char *cmp;
    int znal=0;

    list_band *szukzesp = first;

    while(szukzesp->prev!=NULL) szukzesp=szukzesp->prev;

    list_alb *szukalb = alb_first;

    while(szukalb->prev!=NULL) szukzesp=szukzesp->prev;

    printf("wyniki wyszukiwania bazy zespolow za fraza \"%s\":\n",fraza);

    cmp = fraza;

    while(szukzesp!=NULL)
    {
        if(strcasestr(szukzesp->nazwa,cmp)!=NULL||strcasestr(szukzesp->cz1,cmp)!=NULL||strcasestr(szukzesp->cz2,cmp)!=NULL||strcasestr(szukzesp->cz3,cmp)!=NULL||strcasestr(szukzesp->cz4,cmp)!=NULL||strcasestr(szukzesp->cz5,cmp)!=NULL||strcasestr(szukzesp->cz6,cmp)!=NULL||strcasestr(szukzesp->cz7,cmp)!=NULL||strcasestr(szukzesp->cz8,cmp)!=NULL||strcasestr(szukzesp->cz9,cmp)!=NULL)
        {
            znal=1;
            printf("zespol: %s, zalozony w roku %d,",szukzesp->nazwa,szukzesp->rok_zal);

            if((szukzesp->koniec_dzial>=szukzesp->rok_zal) && (szukzesp->koniec_dzial<=2016)) printf(" zakonczyl dzialalnosc w roku %d,",szukzesp->koniec_dzial);
            else printf(" aktywny po dzis dzien\n");

            printf("czlonkowie:\n%s, %s",szukzesp->cz1,szukzesp->cz2);

            if(strcmp("0",szukzesp->cz3)!=0) printf(", %s",szukzesp->cz3);
            if(strcmp("0",szukzesp->cz4)!=0) printf(", %s",szukzesp->cz4);
            if(strcmp("0",szukzesp->cz5)!=0) printf(", %s",szukzesp->cz5);
            if(strcmp("0",szukzesp->cz6)!=0) printf(", %s",szukzesp->cz6);
            if(strcmp("0",szukzesp->cz7)!=0) printf(", %s",szukzesp->cz7);
            if(strcmp("0",szukzesp->cz8)!=0) printf(", %s",szukzesp->cz8);
            if(strcmp("0",szukzesp->cz9)!=0) printf(", %s",szukzesp->cz9);

            printf("\ngatunki muzyczne, ktore dany zespol wykonuje: %s, %s\n\n",szukzesp->gat1,szukzesp->gat2);
        }
        szukzesp=szukzesp->next;
    }

    if (znal==0) printf("nic nie znaleziono w bazie zespolow :(\n");

    printf("przeszukiwanie bazy albumow za fraza %s ...\n",fraza);

    znal=0;

    while(szukalb!=NULL)
    {
        if (strcasestr(szukalb->nazwa_alb,cmp)!=NULL||strcasestr(szukalb->nazwa_zesp,cmp)!=NULL||strcasestr(szukalb->nazwa_alb,cmp)!=NULL||strcasestr(szukalb->cz1,cmp)!=NULL||strcasestr(szukalb->cz2,cmp)!=NULL||strcasestr(szukalb->cz3,cmp)!=NULL||strcasestr(szukalb->cz4,cmp)!=NULL||strcasestr(szukalb->cz5,cmp)!=NULL||strcasestr(szukalb->cz6,cmp)!=NULL||strcasestr(szukalb->cz7,cmp)!=NULL||strcasestr(szukalb->cz8,cmp)!=NULL||strcasestr(szukalb->cz9,cmp)!=NULL||strcasestr(szukalb->prod,cmp)!=NULL||strcasestr(szukalb->wyd,cmp)!=NULL)
            {
                znal=1;

                printf("album: %s, nagrany przez zespol %s i wydany w roku %d\n",szukalb->nazwa_alb,szukalb->nazwa_zesp,szukalb->rok_wyd);
                printf("czlonkowie, ktorzy nagrali ten album:\n%s, %s",szukalb->cz1,szukalb->cz2);
                if(strcmp("0",szukalb->cz3)!=0)printf(", %s",szukalb->cz3);
                if(strcmp("0",szukalb->cz4)!=0)printf(", %s",szukalb->cz4);
                if(strcmp("0",szukalb->cz5)!=0)printf(", %s",szukalb->cz5);
                if(strcmp("0",szukalb->cz6)!=0)printf(", %s",szukalb->cz6);
                if(strcmp("0",szukalb->cz7)!=0)printf(", %s",szukalb->cz7);
                if(strcmp("0",szukalb->cz8)!=0)printf(", %s",szukalb->cz8);
                if(strcmp("0",szukalb->cz9)!=0)printf(", %s",szukalb->cz9);
                printf("\nproducent: %s, (oryginalny) wydawca albumu: %s\ngatunki wykonywane na tym albumie: %s, %s\n\n",szukalb->prod,szukalb->wyd,szukalb->gat1,szukalb->gat2);
            }
        szukalb=szukalb->next;
    }
    if(znal==0) printf("nie znaleziono nic w bazie albumow :(\n");


    system("pause");
    system("cls");
}

void addzesp (list_band *first)
{
    list_band *new2=calloc(1,sizeof(list_band));
    new2->next=NULL;

    list_band *prz = first;
   // new2->koniec_dzial=1;
    strcpy(new2->cz3,"0");
    strcpy(new2->cz4,"0");
    strcpy(new2->cz5,"0");
    strcpy(new2->cz6,"0");
    strcpy(new2->cz7,"0");
    strcpy(new2->cz8,"0");
    strcpy(new2->cz9,"0");
    strcpy(new2->nazwa,"0");
    strcpy(new2->cz1,"0");
    strcpy(new2->cz2,"0");
    strcpy(new2->gat1,"0");
    strcpy(new2->gat2,"0");

    printf("podaj nazwe zespolu:\n");
    while(strcmp(new2->nazwa,"0")==0)
   {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->nazwa);
   }

    printf("\npodaj rok zalozenia zespolu:\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%4d",&new2->rok_zal);
    printf("\npodaj rok rozwiazania zespolu\n(jezeli takowy wciaz funkcjonuje,podaj byle jaka liczbe nienalezaca do przedzialu [%d,2016]:\n",new2->rok_zal);
    fflush(stdout);
    fflush(stdin);
    scanf("%4d",&new2->koniec_dzial);

    if(new2->koniec_dzial<=new2->rok_zal||new2->koniec_dzial>=2016)
        {
        printf("\nWPROWADZONO LICZBE SPOZA PRZEDZIALU, WIEC UZNAJE, IZ ZESPOL JESZCZE FUNKCJONUJE!\n\n");
        }
    printf("\npodaj nazwe pierwszego czlonka zespolu:\n");
    while(strcmp(new2->cz1,"0")==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz1);
    }
    printf("\npodaj nazwe drugiego czlonka zespolu:\n");
    while(strcmp(new2->cz2,"0")==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz2);
    }
    printf("\npodaj nazwe trzeciego czlonka zespolu (jezeli takowego nie ma, po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz3);
    printf("\npodaj nazwe czwartego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz4);
    printf("\npodaj nazwe piatego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz5);
    printf("\npodaj nazwe szostego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz6);
    printf("\npodaj nazwe siodmego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz7);
    printf("\npodaj nazwe osmego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz8);
    printf("\npodaj nazwe dziewiatego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->cz9);
    printf("\npodaj nazwe pierwszego gatunku muzycznego, ktory twoj zespol wykonuje (najlepiej, gdyby bylo to wyogolnione,\nnp: rock, metal...):\n");
    while(strcmp(new2->gat1,"0")==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->gat1);
    }
    printf("\npodaj nazwe drugiego, bardziej wyszczegolnionego, gatunku muzycznego, ktory twoj zespol wykonuje:\n");
    while(strcmp(new2->gat2,"0")==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",new2->gat2);
    }

   // printf("%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",new2->nazwa,new2->rok_zal,new2->koniec_dzial,new2->cz1,new2->cz2,new2->cz3,new2->cz4,new2->cz5,new2->cz6,new2->cz7,new2->cz8,new2->cz9,new2->gat1,new2->gat2);

    while(prz->next!=NULL) prz=prz->next;

    prz->next=new2;
    new2->prev=prz;

    prz=prz->next;

    while(prz->prev!=NULL)
    {
       // printf("%s",prz->nazwa);
        prz=prz->prev;
    }

        FILE *plik=fopen("zesp.txt","w");

        if(!plik)
        {
            printf("nie znaleziono pliku!");
            exit(-1);
        }

        fseek(plik,0,0);
        while(prz!=NULL)
        {
        fprintf(plik,"%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",prz->nazwa,prz->rok_zal,prz->koniec_dzial,prz->cz1,prz->cz2,prz->cz3,prz->cz4,prz->cz5,prz->cz6,prz->cz7,prz->cz8,prz->cz9,prz->gat1,prz->gat2);
       // printf("%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",prz->nazwa,prz->rok_zal,prz->koniec_dzial,prz->cz1,prz->cz2,prz->cz3,prz->cz4,prz->cz5,prz->cz6,prz->cz7,prz->cz8,prz->cz9,prz->gat1,prz->gat2);
        prz=prz->next;
        }
        fprintf(plik,"\n");

    fclose(plik);

}

void addalb (list_alb *alb_first)
{

    list_alb *alb_new2=calloc(1,sizeof(list_alb));
    alb_new2->next=NULL;

    list_alb *alb_prz = alb_first;
    strcpy(alb_new2->nazwa_alb,"0");
    strcpy(alb_new2->nazwa_zesp,"0");
    strcpy(alb_new2->cz3,"0");
    strcpy(alb_new2->cz4,"0");
    strcpy(alb_new2->cz5,"0");
    strcpy(alb_new2->cz6,"0");
    strcpy(alb_new2->cz7,"0");
    strcpy(alb_new2->cz8,"0");
    strcpy(alb_new2->cz9,"0");
    strcpy(alb_new2->prod,"0");
    strcpy(alb_new2->wyd,"0");
    strcpy(alb_new2->gat1,"0");
    strcpy(alb_new2->gat2,"0");
    strcpy(alb_new2->cz1,"0");
    strcpy(alb_new2->cz2,"0");

    printf("podaj nazwe albumu:\n");
        while(strcmp("0",alb_new2->nazwa_alb)==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%39[^\n]%*c",alb_new2->nazwa_alb);
    }
    printf("\npodaj nazwe zespolu:\n");
    while(strcmp("0",alb_new2->nazwa_zesp)==0)
    {
        fflush(stdout);
        fflush(stdin);
        scanf("%34[^\n]%*c",alb_new2->nazwa_zesp);
    }

    printf("\npodaj rok wydania albumu:\n");
    scanf("%4d",&alb_new2->rok_wyd);

    printf("\npodaj nazwe pierwszego czlonka zespolu:\n");

    while(strcmp("0",alb_new2->cz1)==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz1);
    }

    printf("\npodaj nazwe drugiego czlonka zespolu:\n");

    while(strcmp("0",alb_new2->cz2)==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz2);
    }
    printf("\npodaj nazwe trzeciego czlonka zespolu (jezeli takowego nie ma, po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz3);
    printf("\npodaj nazwe czwartego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz4);
    printf("\npodaj nazwe piatego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz5);
    printf("\npodaj nazwe szostego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz6);
    printf("\npodaj nazwe siodmego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz7);
    printf("\npodaj nazwe osmego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz8);
    printf("\npodaj nazwe dziewiatego czlonka zespolu(jezeli takowego nie ma,po prostu wcisnij enter):\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->cz9);
    printf("\npodaj nazwe producenta albumu:\n");
    while(strcmp("0",alb_new2->prod)==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->prod);
    }

    printf("\npodaj nazwe wydawcy albumu:\n");

    while(strcmp("0",alb_new2->wyd)==0)
    {
    fflush(stdout);
    fflush(stdin);
    scanf("%34[^\n]%*c",alb_new2->wyd);
    }
    printf("\npodaj nazwe pierwszego gatunku muzycznego (najlepiej bardziej ogolna, np. metal, rock itp.):\n");

    while(strcmp("0",alb_new2->gat1)==0)    scanf("%34[^\n]%*c",alb_new2->gat1);

    printf("\npodaj nazwe drugiego, bardziej dokladnego, gatunku muzycznego:\n");

    while(strcmp("0",alb_new2->gat2)==0)    scanf("%34[^\n]%*c",alb_new2->gat2);

    //printf("%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",alb_new2->nazwa_alb,alb_new2->nazwa_zesp,alb_new2->rok_wyd,alb_new2->cz1,alb_new2->cz2,alb_new2->cz3,alb_new2->cz4,alb_new2->cz5,alb_new2->cz6,alb_new2->cz7,alb_new2->cz8,alb_new2->cz9,alb_new2->prod,alb_new2->wyd,alb_new2->gat1,alb_new2->gat2);

    while(alb_prz->next!=NULL) alb_prz=alb_prz->next;

    alb_prz->next=alb_new2;
    alb_new2->prev=alb_prz;

    alb_prz=alb_prz->next;

    while(alb_prz->prev!=NULL)
    {
        //printf("%s",alb_prz->nazwa_alb);
        alb_prz=alb_prz->prev;
    }
        FILE *plik=fopen("alb.txt","w");

    if(!plik)
    {
        printf("nie znaleziono pliku!");
        exit(-1);
    }
        fseek(plik,0,0);
        while(alb_prz!=NULL)
        {
        fprintf(plik,"%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",alb_prz->nazwa_alb,alb_prz->nazwa_zesp,alb_prz->rok_wyd,alb_prz->cz1,alb_prz->cz2,alb_prz->cz3,alb_prz->cz4,alb_prz->cz5,alb_prz->cz6,alb_prz->cz7,alb_prz->cz8,alb_prz->cz9,alb_prz->prod,alb_prz->wyd,alb_prz->gat1,alb_prz->gat2);
        alb_prz=alb_prz->next;
        }
    fprintf(plik,"\n");

    fclose(plik);
}

void usunzesp(list_band *first) /* BUG - gdy wykona sie przy odpalonym programie 2 operacje naraz - pojawia sie "smieciowy"
 (pochodzacy z poprzedniej operacji) element listy. Wszystko jest OK gdy po wykonaniu 1. operacji zamknie sie program i
  uruchomi sie go na nowo*/
{
    fflush(stdin);
    fflush(stdout);
    list_band *usunband=first;
    list_band *usun;
    int znal=0;

    fflush(stdin);
    fflush(stdout);


    char fraza[34]="1";
    printf("podaj nazwe zespolu, ktorego to rekord chcesz usunac:");
    scanf("%34[^\n]%*c",fraza);

    while(usunband!=NULL)
    {
        if(strcasecmp(fraza,usunband->nazwa)==0)
        {
            znal=1;
            usun=usunband;
            if(usunband->next!=NULL)
            {
                usunband=usunband->next;
                if(usun->prev!=NULL)
                {
                    usunband->prev=usun->prev;
                    usun->prev->next=usunband;
                }
                else
                {
                    usunband->prev=NULL;
                }
            }
            else if(usun->prev!=NULL)
                {
                    usunband=usunband->prev;
                    usunband->next=NULL;
                }
            printf("\n\nusuwam:%s\n\n",usun->nazwa);
            free(usun);
            break;
        }
        else usunband=usunband->next;
    }

    if(znal!=1)
    {
        system("cls");
        printf("nie znaleziono podanego zespolu!\n");
        system("pause");
    }
    else
    {
        while(usunband->prev!=NULL)
        {
      //  printf("\\zespol:%s\n",usunband->nazwa);
        usunband=usunband->prev;
        }

        FILE *plik = fopen("zesp.txt","w");

        if(!plik)
        {
            printf("nie znaleziono pliku!!!\nNastapi przerwanie programu...");
            exit(-1);
        }
            while(usunband!=NULL)
            {
                fprintf(plik,"%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",usunband->nazwa,usunband->rok_zal,usunband->koniec_dzial,usunband->cz1,usunband->cz2,usunband->cz3,usunband->cz4,usunband->cz5,usunband->cz6,usunband->cz7,usunband->cz8,usunband->cz9,usunband->gat1,usunband->gat2);
               // printf("%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",usunband->nazwa,usunband->rok_zal,usunband->koniec_dzial,usunband->cz1,usunband->cz2,usunband->cz3,usunband->cz4,usunband->cz5,usunband->cz6,usunband->cz7,usunband->cz8,usunband->cz9,usunband->gat1,usunband->gat2);
            usunband=usunband->next;
            }
        fclose(plik);

    }
}

void usunalb(list_alb *alb_first)
{
    list_alb *usunalb=alb_first;
    list_alb *usun;
    int znal=0;

   //char smiec_zesp[35];

    char album[35]="1";
    char band[35]="1";
    printf("podaj nazwe album, ktorego to rekord chcesz usunac:");
    scanf("%34[^\n]%*c",album);
    printf("podaj nazwe zespolu, ktory ten album nagral:");
    scanf("%34[^\n]%*c",band);


    while(usunalb!=NULL)
    {
        if(strcasecmp(album,usunalb->nazwa_alb)==0&&strcasecmp(band,usunalb->nazwa_zesp)==0)
        {
            znal=1;
            usun=usunalb;
            if(usunalb->next!=NULL)
            {
                usunalb=usunalb->next;
                if(usun->prev!=NULL)
                {
                    usunalb->prev=usun->prev;
                    usun->prev->next=usunalb;
                }
                else
                {
                    usunalb->prev=NULL;
                }
            }
            else if(usun->prev!=NULL)
                {
                    usunalb=usunalb->prev;
                    usunalb->next=NULL;
                }
            printf("\n\nusuwam:%s\n\n",usun->nazwa_alb);
            free(usun);
            break;

        }
        else usunalb=usunalb->next;
    }
    if(znal==0)
    {
        system("cls");
        printf("nie znaleziono podanego albumu...\n");
        system("pause");
    }
    else
    {

        while(usunalb->prev!=NULL)
        {
       // printf("\nalbum:%s\n",usunalb->nazwa_alb);
        usunalb=usunalb->prev;
        }


        FILE *plik = fopen("alb.txt","w");

        if(!plik)
        {
            printf("nie znaleziono pliku!!!\nNastapi przerwanie programu...");
            exit(-1);
        }
            while(usunalb!=NULL)
            {
              //  printf("wpisuje album:%s\n",usunalb->nazwa_alb);
                fprintf(plik,"%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",usunalb->nazwa_alb,usunalb->nazwa_zesp,usunalb->rok_wyd,usunalb->cz1,usunalb->cz2,usunalb->cz3,usunalb->cz4,usunalb->cz5,usunalb->cz6,usunalb->cz7,usunalb->cz8,usunalb->cz9,usunalb->prod,usunalb->wyd,usunalb->gat1,usunalb->gat2);
                usunalb=usunalb->next;
            }
        fclose(plik);
    }
}

void zlat(list_band *first, list_alb *alb_first)
{
    int rok;
    int znal = 0;
    printf("\npodaj, z ktorych lat podac liste zespolow i albumow\n(np. wpisz 90 dla listy zespolow/albumow z lat 1990-1999,\nlub 00 dla zespolow/albumow z lat 2000-2009):\n");
    while(rok%10!=0||(rok<=0 && rok>=100))
    {
        fflush(stdin);
        fflush(stdout);
        scanf("%d",&rok);
        if(rok%10!=0) printf("podaj poprawna forme lat! (czyli 60,70,80,90...)");
    }

    if(rok>=0 && rok<=10) rok = rok+2000;
    else rok = rok+1900;

    //printf("%d",rok);

    list_band *zlatband = first;
    list_alb *zlatalb = alb_first;

    printf("przeszukuje baze \"zespoly\":\n\n");
    while(zlatband!=NULL)
    {
        if(zlatband->rok_zal>=rok && zlatband->rok_zal<=(rok+9))
        {
            znal=1;
            printf("zespol: %s, zalozony w %d roku.\n",zlatband->nazwa,zlatband->rok_zal);
        }
        zlatband=zlatband->next;
    }
    if(znal==0) printf("brak zespolu zalozonego w tych latach...\n");
    printf("\n");

    znal=0;

    printf("przeszukuje baze \"albumy\"...\n\n");

    while(zlatalb!=NULL)
    {
        if(zlatalb->rok_wyd>=rok&&zlatalb->rok_wyd<=(rok+9))
        {
            znal=1;
            printf("album: %s, w wykonaniu zespolu %s, wydany w roku %d.\n",zlatalb->nazwa_alb,zlatalb->nazwa_zesp,zlatalb->rok_wyd);
        }
        zlatalb=zlatalb->next;
    }

    if(znal==0) printf("brak albumu nagranego w podanych latach...\n");
    printf("\n");

    system("pause");
    system("cls");

}

void edyt(list_band *first, list_alb *alb_first)
{
    char baza [5]="-1";
    char fraza[35];
    char zespol[35];
    int znal = 0;
    list_band *edytband=first;
    list_alb *edytalb=alb_first;

    while(strcmp(baza,"1")!=0&&strcmp(baza,"2")!=0&&strcmp(baza,"0")!=0)
    {
        printf("\nwybierz, z ktorej bazy chcesz dokonac edycji rekordu:\n1 - zespoly,\n2 - albumy,\n0 - anulowanie operacji");
        fflush(stdin);
        fflush(stdout);
        scanf("%3s",baza);

        if(strcmp(baza,"1")!=0&&strcmp(baza,"2")!=0&&strcmp(baza,"0")!=0)
        {
            system("cls");
            printf("podano nieprawidlowy wybor!\n");
        }
    }


    if(strcmp(baza,"1")==0)
    {
        printf("\npodaj nazwe zespolu, ktorego rekord chcesz edytowac:\n");
        fflush(stdin);
        fflush(stdout);
        scanf ("%34[^\n]%*c", fraza);

        while(edytband!=NULL)
        {
            if(strcasecmp(fraza,edytband->nazwa)==0)
            {
                znal=1;

                printf("\nzespol: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->nazwa);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->nazwa);
                printf("%s",edytband->nazwa);

                printf("\nrok zalozenia: %d\nedycja na: (jesli nie chcesz edytowac, wpisz rok podany powyzej)",edytband->rok_zal);
                fflush(stdin);
                fflush(stdout);
                scanf("%5d", &edytband->rok_zal);

                printf("\nrok rozwiazania zespolu: %d\nedycja na: (jesli nie chcesz edytowac, wpisz rok (badz liczbe) podana powyzej)",edytband->koniec_dzial);
                fflush(stdin);
                fflush(stdout);
                scanf("%5d", &edytband->koniec_dzial);

                printf("\nczlonek zespolu nr.1: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz1);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz1);
                 printf("%s",edytband->cz1);

                printf("\nczlonek zespolu nr.2: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz2);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz2);

                printf("\nczlonek zespolu nr.3: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz3);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz3);

                printf("\nczlonek zespolu nr.4: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz4);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz4);

                printf("\nczlonek zespolu nr.5: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz5);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz5);

                printf("\nczlonek zespolu nr.6: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz6);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz6);

                printf("\nczlonek zespolu nr.7: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz7);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz7);

                printf("\nczlonek zespolu nr.8: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz8);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz8);

                printf("\nczlonek zespolu nr.9: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->cz9);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->cz9);

                printf("\npierwszy gatunek muzyczny: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->gat1);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->gat1);

                printf("\ndrugi gatunek muzyczny: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytband->gat2);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytband->gat2);

                break;

            }

            edytband=edytband->next;
        }
        if(znal==0) printf("\nnie znaleziono podanego zespolu...\n");

        else
            {
            while(edytband->prev!=NULL) edytband=edytband->prev;

            FILE *plikz=fopen("zesp.txt","w");
            if(!plikz) abort();

            fseek(plikz,0,0);

            while(edytband!=NULL)
            {
                fprintf(plikz,"%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",edytband->nazwa,edytband->rok_zal,edytband->koniec_dzial,edytband->cz1,edytband->cz2,edytband->cz3,edytband->cz4,edytband->cz5,edytband->cz6,edytband->cz7,edytband->cz8,edytband->cz9,edytband->gat1,edytband->gat2);
                edytband=edytband->next;
            }

            fclose(plikz);

            }
    }

    else if (strcmp(baza,"2")==0)
    {
        printf("\npodaj nazwe albumu, ktorego rekord chcesz edytowac:\n");
        fflush(stdin);
        fflush(stdout);
        scanf("%34[^\n]*c",fraza);
        printf("\npodaj nazwe zespolu, ktorego rekord chcesz edytowac:\n");
        fflush(stdin);
        fflush(stdout);
        scanf("%34[^\n]*c",zespol);

        while(edytalb!=NULL)
        {
            if(strcasecmp(fraza,edytalb->nazwa_alb)==0&&strcasecmp(zespol,edytalb->nazwa_zesp)==0)
            {
                znal=1;

                printf("\nnazwa albumu: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->nazwa_alb);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->nazwa_alb);

                printf("\nzespol: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->nazwa_zesp);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->nazwa_zesp);

                printf("\nrok wydania albumu: %d\nedycja na: (jesli nie chcesz edytowac, wpisz ten sam rok, co podany powyzej)",edytalb->rok_wyd);
                fflush(stdin);
                fflush(stdout);
                scanf("%5d", &edytalb->rok_wyd);

                printf("\nowczesny czlonek zespolu nr.1: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz1);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz1);

                printf("\nowczesny czlonek zespolu nr.2: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz2);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz2);

                printf("\nowczesny czlonek zespolu nr.3: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz3);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz3);

                printf("\nowczesny czlonek zespolu nr.4: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz4);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz4);

                printf("\nowczesny czlonek zespolu nr.5: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz5);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz5);

                printf("\nowczesnyczlonek zespolu nr.6: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz6);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz6);

                printf("\nowczesnyczlonek zespolu nr.7: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz7);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz7);

                printf("\nowczesnyczlonek zespolu nr.8: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz8);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz8);

                printf("\nowczesnyczlonek zespolu nr.9: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->cz9);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->cz9);

                printf("\nproducent albumu: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->prod);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->prod);

                printf("\nwydawca albumu: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->wyd);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->wyd);

                printf("\npierwszy gatunek muzyczny, wystepujacy na albumie: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->gat1);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->gat1);

                printf("drugi gatunek muzyczny, wystepujacy na albumie: %s\nedycja na: (jesli nie chcesz edytowac, wcisnij enter)",edytalb->gat2);
                fflush(stdin);
                fflush(stdout);
                scanf("%34[^\n]%*c", edytalb->gat2);

                break;
            }

            edytalb=edytalb->next;
        }

        if (znal==0) printf("nie znaleziono podanego albumu\n");

        else
        {
            while(edytalb->prev!=NULL) edytalb=edytalb->prev;

            FILE *plika = fopen("alb.txt","w");

            if(!plika) abort();

            fseek(plika,0,0);

            while(edytalb!=NULL)
            {
                fprintf(plika,"%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",edytalb->nazwa_alb,edytalb->nazwa_zesp,edytalb->rok_wyd,edytalb->cz1,edytalb->cz2,edytalb->cz3,edytalb->cz4,edytalb->cz5,edytalb->cz6,edytalb->cz7,edytalb->cz8,edytalb->cz9,edytalb->prod,edytalb->wyd,edytalb->gat1,edytalb->gat2);
                edytalb=edytalb->next;
            }

            fclose(plika);
        }
    }

    if (strcmp(baza,"1")==0||strcmp(baza,"2")==0) system("pause");
    system ("cls");
}
