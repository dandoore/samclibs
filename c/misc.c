//
//    Sam Coupe extra functions for DOS etc.
//    misc.c
//
//    (C) 1995 RUMSOFT 13.11.1995
//

#ifdeclared getpixel
int getpixel(int x, int y)
{
    #asm
    pop bc
    pop de
    pop hl
    push hl
    push de
    push bc
    ld  a,191
    sub e
    ld  d,a
    ld  e,l
    ex  de,hl
    scf
    rr h
    rr l
    push af
    call &3fbb
    ld l,a
    pop af
    ld a,l
    jr c,bezpod
    rrca
    rrca
    rrca
    rrca
bezpod: and 15
    ld l,a
    ld h,0
#endasm
}
#endif


//
// get video mode number 1..4
//
#ifdeclared getgraphmode
int getgraphmode(void )
{
    #asm
    in a,(&fc)
    and %01100000
    rlca
    rlca
    rlca
    inc a
    ld l,a
    ld h,0
    #endasm
}
#endif


#ifdeclared circle
void circle(int x, int y, int r)

/* NOTES: This is the function which draws a circle. The
parameters passed on calling it are:
int x = X co-ordinate of centre of circle
int y = Y co-ordinate of centre of circle
int r = radius in pixels.
None of these co-ordinates may be greater than 255, which means
that circles cannot be drawn at all possible centre points on
the mode 3 screen, on which X co-ordinates go above 255.
Apart from that, it works just like the BASIC CIRCLE command,
with the Y co-ordinate zero at the top.

Carol Brooksbank    April 1995     */

{
#asm
pop af
pop hl
pop de
pop bc
push bc
push de
push hl
push af
ld b,e
ld d,l
ld e,l
push de
pop af
call &0142
#endasm
}
#endif


//
// for screen colour
//
#ifdeclared setbkcolor, setcolor

void setbkcolor(int color)
{
#asm
    call _uprcol
    ld (&5a51),a
    ld (&5a48),a
    ld (&5a30),a
#endasm
}

void setcolor(int color)
{
#asm
    call _uprcol
    ld (&5a52),a
    ld (&5a49),a
    ld (&5a31),a
#endasm
}

#asm
_uprcol: ld a,l
    and 15
    ld l,a
    rrca
    rrca
    rrca
    rrca
    or l
    ret
#endasm
#endif

//
// as BASIC OVER 0-3
//
#ifdeclared setdrawmode
void setdrawmode(int m)
{
    _blitz(OVER, m);
}
#endif

#ifdeclared _blitz
void _blitz(int command, int m)

{
    int i;
    i = command+m*256;
    blitz(&i, 2);
}
#endif

//
// as BASIC BLITZ string of command and number of one
//
#ifdeclared blitz
void blitz(char *s, int cnt)
{
#asm
pop hl
pop bc
pop de
push de
push bc
push hl
call &148
#endasm
}
#endif


//
// call user routine with registers parameters
//
#ifdeclared user

REGS regs;
int user(unsigned adr)
{
    #asm
    ld  (_usera),hl
    ld  a,(regs)
    ld  bc,(regs+1)
    ld  de,(regs+3)
    ld  hl,(regs+5)
    ld  ix,(regs+7)
    ld  iy,(regs+8)
    db  &cd
_usera: dw 0
    ld  (regs),a
    ld  (regs+1),bc
    ld  (regs+3),de
    ld  (regs+5),hl
    ld  (regs+7),ix
    ld  (regs+8),iy
    #endasm
}
#endif


#ifdeclared mdriver, xmouse, ymouse, button

//
// return TRUE if mouse is installed
//
int mdriver(void )
{
    return ( (*(int *) 0x5AFC) ? 1:0);
}

//
// return x-position of mouse pointer
//
unsigned xmouse(void )
{
    return ( (*(int *) 0x5B96));
}

//
// return y-position of mouse pointer

//
unsigned ymouse(void )
{
    return ( (*(char *) 0x5B98));
}

//
// return number of mouse button that is pushed
//
int button(void )
{
    static int bu;
    bu = (*(char *) 0x5B8F) & 7;
    return ((bu == 4) ? 3 : bu);
}
#endif


#ifdeclared setpalette, setallpalette
void setpalette(int pos,int col)
    {
    #asm
    pop hl
    pop bc
    pop de
    push de
    push bc
    push hl
    ld b,c
    ld a,-1
    call &154
    #endasm
    }

void setallpalette( char *p)
    {
    static int ind;
    for (ind=0; ind != 16; ind++ )
        palette(ind, *p++ );
    }
#endif

#ifdeclared outtextxy
void outtextxy(int x, int y, char *s)
{
    at(y,x);
    print(s);
}
#endif



