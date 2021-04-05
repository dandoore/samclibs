//
//    Sam Coupe standard C system function header
//    system.h
//
//    (C) 1994 RUMSOFT
//

#ifndef SYSTEM
#define SYSTEM
extern void disable();
extern void enable();

extern unsigned inp(unsigned p);
extern unsigned outp(unsigned p,int v);

extern int escape();
extern int avail();

extern void poke(unsigned a, char b);
extern void dpoke(unsigned a, int b);
extern char peek(unsigned a);
extern int dpeek(unsigned a);

extern int callcode (int a,int b,int d,int h,unsigned adr);

extern void pause(int c);
extern int gettime();
extern int getsp();
#endif



