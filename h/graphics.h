//
//    Sam Coupe standard graphics headers
//    graphics.h
//
//    (C) 1994 RUMSOFT - Last update: 01.10.95
//

#ifndef GRAPHICS
#define GRAPHICS
extern void moveto(int x, int y);
extern void plot(int x, int y);
extern void drawto(int x, int y);
extern void line(int x0, int y0, int x1, int y1);
extern void circle(int x, int y, int r);
extern void box(int x, int y, int w, int l);
extern void cls(int a);
extern void put(int x, int y, int mode);
extern unsigned grab(int x, int y, int w, int l);
extern void fill(int x, int y, int mode);
extern void mode(int m);
extern void open_scr(int scr, int mode);
extern void display(int scr);
extern void close_scr(int scr);
extern void palette(int pos, int col);
extern void allpalette(int pal);
extern void triangle(int x0, int y0, int x1, int y1, int x2, int y2);
extern int setpattern(int p);
extern void pen(int i);
extern void paper(int p);
extern void setover(int m);
extern int getx();
extern int gety();
extern void fatpix(int a);
extern void scroll(int x, int y, int width, int length, int direct, int size);
extern void roll  (int x, int y, int width, int length, int direct, int size);
extern void border(int a);
#endif



