//
//    Sam Coupe standard 'C' string <-> number conversion header
//    string2.h
//
//    (C) 1995 RUMSOFT - Last update: 07.01.95
//

#ifndef STRING2
#define STRING2
extern int otoi(char *octstr, int nbr);
extern int utoi(char *decstr, int nbr);
extern int xtoi(char *hexstr, int nbr);
extern int dtoi(char *decstr, int nbr);

extern char * itoo(int nbr, char *str, int sz);
extern char * itou(int nbr, char *str, int sz);
extern char * itox(int nbr, char *str, int sz);
extern char * itod(int nbr, char *str, int sz);

extern void reverse(char *s);
extern void left(char *s);
#endif



