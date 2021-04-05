//
//    Sam Coupe Test of some MISC functions - mouse driver is required
//    demo_testmisc.c
//
//    (C) 1995 RUMSOFT                          
//

#include "stdio.h"
#include "misc.h"
#include "graphics.h"

main()
{
    setcolor(12);
    setbkcolor(1);
    border(1);
    clscr();
    printf("\n         Video mode = %u", getgraphmode());
    setcolor(15);
    circle(128, 96, 50);
    circle(128, 96, 40);
    circle(128, 96, 30);
    if (mdriver())
    {
        plot(xmouse(), ymouse());
        while (button() != 3)
        {
            printf("\a\x0e\x0b %3u:%3u ", xmouse(), ymouse());
            drawto(xmouse(), ymouse());
            if (button() == 1) clscr();
            printf("\a\0\0Button: %u", button());
        }
    }
    else
    {
        outtextxy(5, 17, "Mouse isn't installed !");
    }
}

#include "misc.c"
#include "graphics.c"



