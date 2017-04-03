#include <stdlib.h>
#include <stdio.h>
#include "init_alb.h"

int init_alb(list_alb *alb_first)
{
    //char comp[]="0";
    list_alb *alb = alb_first;
    list_alb *albpoprz;
    FILE *album = fopen ("alb.txt","r");
            if(!album)
            {
                perror("blad pliku");
                exit(-3);
            }

        /* SKANOWANIE PLIKU I PRZEPISYWANIE DO LISTY: */

      while (1)
    {
        list_alb *albnew = calloc(1,sizeof(list_alb));

        fscanf(album,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",albnew->nazwa_alb,albnew->nazwa_zesp,&albnew->rok_wyd,albnew->cz1,albnew->cz2,albnew->cz3,albnew->cz4,albnew->cz5,albnew->cz6,albnew->cz7,albnew->cz8,albnew->cz9,albnew->prod,albnew->wyd,albnew->gat1,albnew->gat2);

        if(alb_first->rok_wyd==NULL)
        {
            alb_first=albnew;
            alb=alb_first;
        }
        else
        {
            albpoprz=alb;
            alb->next=albnew;
            alb=alb->next;
            alb->prev=albpoprz;
        }
        alb->next=NULL;
        if (feof(album)!=0)
        {
            break;
        }

    }

        while(alb->prev!=NULL)
        {
            alb=alb->prev;
        }
    /* SPRAWDZANIE, CZY PROGRAM POPRAWNIE SKOPIOWAL Z PLIKU Z ALBUMAMI:
  while (alb!=NULL)
    {

        printf("%s, %s, %d, %s, %s, ",alb->nazwa_alb,alb->nazwa_zesp,alb->rok_wyd,alb->cz1,alb->cz2);
        if (strcmp(alb->cz3,comp)!=0) printf("%s, ",alb->cz3);
        if (strcmp(alb->cz4,comp)!=0) printf("%s, ",alb->cz4);
        if (strcmp(alb->cz5,comp)!=0) printf("%s, ",alb->cz5);
        if (strcmp(alb->cz6,comp)!=0) printf("%s, ",alb->cz6);
        if (strcmp(alb->cz7,comp)!=0) printf("%s, ",alb->cz7);
        if (strcmp(alb->cz8,comp)!=0) printf("%s, ",alb->cz8);
        if (strcmp(alb->cz9,comp)!=0) printf("%s, ",alb->cz9);
        printf("%s, %s, %s, %s\n",alb->prod,alb->wyd,alb->gat1,alb->gat2);
        alb=alb->next;
    }
*/

    fclose(album);
    return alb;
}


