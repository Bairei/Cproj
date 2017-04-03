#ifndef STRUCT_ZESP_H
#define STRUCT_ZESP_H
typedef struct band
{
    char nazwa[35];
    int rok_zal;
    int koniec_dzial;
    char cz1[35];
    char cz2[35];
    char cz3[35];
    char cz4[35];
    char cz5[35];
    char cz6[35];
    char cz7[35];
    char cz8[35];
    char cz9[35];
    char gat1[35];
    char gat2[35];
    struct band *next;
    struct band *prev;
} list_band;
#endif // STRUCT_ZESP_H
