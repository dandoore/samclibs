//
//    Sam Coupe String Test
//    demo_teststring.c
//
//    (C) 1995 RUMSOFT                                
//

#pragma option l-
#include "string.h"
#include "ctype.h"
main()
{
  char s[30];
  clscr();
  strnset(s, ' ', 29);
  printf("[%s]\n", s);
  stpcpy(s, " a stRing");
  printf("[%s]\n", s);
  strupr(s);
  printf("[%s]\n", s);
  strlwr(s);
  printf("[%s]\n", s);
  printf("[%s]\n", strstr(s, "ri"));
}
#include "string.c"
#include "ctype.c"


