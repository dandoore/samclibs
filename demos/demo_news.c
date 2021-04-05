//
//    Sam Coupe news demo
//    demo_news.c
//
//    (C) 1995 RUMSOFT  
//              

#include "stdio.h"
#include "conio.h"
#include "graphics.h"
#pragma option i-

main()
{
    int a,b,c;
    register unsigned d;

    a=5;
    b=7;
    d=56000;
    c=b+a;
    c=a+3;   // there is OK lines
    c=a+b;

    pen(15);
    paper(1);
    border(1);
    clscr();

    printf("\p\6The answer is %d\n" ,c);
    printf("\i\4Integer  = %d\n", d);
    printf("Unsigned = %u\n", d); // used the %u switcher

    /* \i and \p are new */

    printf("Heap size : %u\n", heaplen_);
    printf("Stack size: %u\n", stklen_);

    d=0U; // explicit unsigned const ant !

    printf("Variable d before evaluation = %d\n", d);

    d=(a>b)?1:2; // OK

    printf("Variable d after evaluation  = %d\n", d);

    printf("scanf test: ");

    scanf("%d", &d);

    printf("Variable d after scanf  = %d\n", d);

    getche(); // The CAPS pressing is ROM ERROR !!!
}
#include "conio.c"
#include "graphics.c"



