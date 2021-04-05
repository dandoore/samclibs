//
//    Sam Coupe standard C library headers file
//    stdlib.h
//
//    (C) 1995 RUMSOFT 22.08.95
//

#ifndef STDLIB
#define STDLIB
extern void abort(int c);
extern int abs(int x);
extern int atexit(int fnc);
extern int atoi(int s);
extern void exit(int a);
extern void tdump();
extern void gdump();
extern char * itoa(int value, char *string, int radix);
extern int max (int a, int b);
extern int min (int a, int b);
extern void sort(char *base,int offset, int size, int items, int (*comp)(), int (*swap)());
extern int rand();
extern void srand(int seed);
extern void swap(unsigned width, unsigned from, unsigned to);
extern void beep(int duration, int pitch);
extern void sound(...);
extern void nosound();
extern int is512kb();
extern int outprn(int c);
#endif



