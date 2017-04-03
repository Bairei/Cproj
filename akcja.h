#ifndef AKCJA_H
#define AKCJA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct_zesp.h"
#include "struct_alb.h"
#include "init_zesp.h"
#include "init_alb.h"

char *strcasestr(const char *haystack, const char *needle);
void szukajfraz(char *fraza, list_band *first, list_alb *alb_first);

void addzesp (list_band *first);
void addalb (list_alb *alb_first);

void usunzesp(list_band *first);
void usunalb(list_alb *alb_first);

void zlat (list_band *first, list_alb *alb_first);

void edyt(list_band *first, list_alb *alb_first);

#endif // AKCJA_H
