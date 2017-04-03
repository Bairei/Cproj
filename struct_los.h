#ifndef STRUCT_LOS_H
#define STRUCT_LOS_H
typedef struct los{
char *nazwa_zesp;
char *nazwa_alb;
struct los *next;
struct los *prev;
} list_los;
#endif // STRUCT_LOS_H
