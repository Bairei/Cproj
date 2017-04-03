#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "init_zesp.h"

int init_zesp(list_band *first)
{
    //char comp[]="0";
    list_band *zesp = first;
    list_band *poprz;
    FILE *zespol = fopen ("zesp.txt","r");
            if(!zespol)
            {
                perror("blad pliku");
                exit(-3);
            }

        /* SKANOWANIE PLIKU I PRZEPISYWANIE DO LISTY: */

      while (1)
    {
        list_band *new = calloc(1,sizeof(list_band));

        fscanf(zespol,"%[^,],%d,%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",new->nazwa,&new->rok_zal,&new->koniec_dzial,new->cz1,new->cz2,new->cz3,new->cz4,new->cz5,new->cz6,new->cz7,new->cz8,new->cz9,new->gat1,new->gat2);

        if(first==NULL)
        {
            first=new;
            zesp=first;
        }
        else
        {
            poprz=zesp;
            zesp->next=new;
            zesp=zesp->next;
            zesp->prev=poprz;
        }
        zesp->next=NULL;
        if (feof(zespol)!=0)
        {
            break;
        }

    }

        while(zesp->prev!=NULL)
        {
            zesp=zesp->prev;
        }

  /*  SPRAWDZANIE, CZY PROGRAM POPRAWNIE SKOPIOWAL Z PLIKU Z ZESPOLAMI:
  while (zesp!=NULL)
    {

        printf("%s, %d - ",zesp->nazwa,zesp->rok_zal);
         if(((zesp->koniec_dzial)<=2016) && (zesp->koniec_dzial >= zesp->rok_zal))  printf("%d, ",zesp->koniec_dzial);
         else printf("do teraz, ");
        printf("%s, %s, ",zesp->cz1,zesp->cz2);
        if (strcmp(zesp->cz3,comp)!=0) printf("%s, ",zesp->cz3);
        if (strcmp(zesp->cz4,comp)!=0) printf("%s, ",zesp->cz4);
        if (strcmp(zesp->cz5,comp)!=0) printf("%s, ",zesp->cz5);
        if (strcmp(zesp->cz6,comp)!=0) printf("%s, ",zesp->cz6);
        if (strcmp(zesp->cz7,comp)!=0) printf("%s, ",zesp->cz7);
        if (strcmp(zesp->cz8,comp)!=0) printf("%s, ",zesp->cz8);
        if (strcmp(zesp->cz9,comp)!=0) printf("%s, ",zesp->cz9);
        printf("%s, %s\n",zesp->gat1,zesp->gat2);
        zesp=zesp->next;
    }
*/

    fclose(zespol);

    return zesp;
}
