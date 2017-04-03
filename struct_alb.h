#ifndef STRUCT_ALB_H
#define STRUCT_ALB_H
typedef struct alb{
char nazwa_alb[40];
char nazwa_zesp[35];
int rok_wyd;
char cz1[35];
char cz2[35];
char cz3[35];
char cz4[35];
char cz5[35];
char cz6[35];
char cz7[35];
char cz8[35];
char cz9[35];
char prod[35];
char wyd[35];
char gat1[30];
char gat2[30];
struct alb *next;
struct alb *prev;

}list_alb;
#endif // STRUCT_ALB_H
