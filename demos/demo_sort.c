//
//    Demo of Quicksort based on the algorithm given in "Algorithms + Data Structures = Programs" by N. Wirth.
//    demo_sort.c
//
//    (C) 1995 RUMSOFT 13.11.1995    
//                                 

#include "stdio.h"

qsort(char *base, int (*compar)(),
unsigned width, unsigned nel)
{
  char *x, xbuf[800];
  int i,j,l,r,s;
  static struct { int ls,rs;} stack[20];

  if (width < 800)
    x = xbuf;
  else if (!(x = malloc(width+1)))
    return ;      /* can't do much */
  x[width] = 0;
  s = 0;
  stack[0].ls = 0;
  stack[0].rs = nel-1;
  do {
    /* take top request from stack */
    l = stack[s].ls;
    r = stack[s-- ].rs;

    do {
      i = l;
      j = r;
      bmove(base+width*((i+j)/2), x, width);
      do {
        while ((*compar)(base+i*width, x) < 0)
          i++ ;
        while ((*compar)(x, base+j*width) < 0)
          j-- ;
        if (i <= j) {
          _swap(width, base+i*width, base+j*width);
          i++ ;
          j-- ;
        }
      } while (i <= j);
      if (j-l < r-i) {
        if (i < r) {  /* stack right partition */
          stack[++ s].ls = i;
          stack[s].rs = r;
        }
        r = j;    /* continue with left */
      } else {
        if (l < j) {
          stack[++ s].ls = l;
          stack[s].rs = j;
        }
        l = i;
      }
    } while (l < r);
  } while (s >= 0);
  if (x != xbuf)
    free(x);
}


