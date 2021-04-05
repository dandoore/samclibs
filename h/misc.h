//
//    Sam Coupe extra functions for DOS etc. header
//    misc.h
//
//    (C) 1995 RUMSOFT 13.11.1995
//                                  

#ifndef MISC
#define MISC
typedef struct { unsigned char numcolor[16]; } PALETTE;
typedef struct { unsigned char _A_; unsigned _BC, _DE, _HL, _IX, _IY;} REGS;
extern REGS regs;
enum GCode { PLOT=1, DRAWTO, CIRCLE, OVER, PEN, CLS, PAUSE };
int blitz(...);
int getgraphmode(void );
int getpixel(int x, int y);

#define outtext puts
void outtextxy(int x, int y, char *s);

#define putpixel(a,b,c) {pen(c);plot(a,b);}
void setdrawmode(int a);
void setallpalette(PALETTE *p);
void setpalette(int num, int color);
void circle(int x, int y, int radius);
void setbkcolor(int color);
void setcolor(int color);
int user(unsigned addr);
int mdriver(void );
int xmouse(void );
int ymouse(void );
int button(void );
#endif



