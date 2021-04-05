//
//    Sam Coupe C graphics
//    graphics.c
//
//    (C) 1995 RUMSOFT - Last update: 01.10.95
//


#ifdeclared line
void line(int a, int b, int x, int y)
    {
    plot(a,b);
    drawto(x,y);
    }
#endif


#ifdeclared box
void box(int x, int y, int width, int depth)
    {
    plot(x,y);
    drawto(x+width,y);
    drawto(x+width,y+depth);
    drawto(x,y+depth);
    drawto(x,y);
    }
#endif


#ifdeclared cls
void cls (int a)
{
#asm
ld a,l
call &14e
ld a,2
call &112
#endasm
}
#endif


#ifdeclared put, grab
void put(int x,int y,int mode)
{
#asm
push ix
ld ix,0
add ix,sp
ld b,(ix+6)
ld c,(ix+8)
ld a,191
sub b
ld b,a
ld hl,&e001
ld a,(ix+4)
call &133
pop ix
#endasm
}

/* get sprite */

unsigned grab (int x,int y,int width,int length)
{
#asm
push ix
ld ix,0
add ix,sp
ld e,(ix+6)
ld d,(ix+7)
rrc d
rr  e
ld d,(ix+4)
ld b,(ix+8)
ld c,(ix+10)
ld a,191
sub b
ld b,a
call &136
ld l,c
ld h,b
pop ix
#endasm
/* vracia dlzku dat */
}
#endif


#ifdeclared fill
void fill(int x, int y, int mode)
    {
    #asm
    pop hl
    exx
    pop hl
    ld a,l
    ld de,(fillpatt)
    pop bc
    pop hl
    ld b,c
    ld c,l
    ex af,af'
    ld a,191
    sub b
    ld b,a
    ex af,af'
    exx
    push hl
    push hl
    push hl
    push hl
    exx
    call &145
    #endasm
    }

unsigned fillpatt=0;

void setpattern(char *p)
    {
    #asm
    ld (fillpatt),hl
    #endasm
    }
#endif

#ifdeclared mode
void mode(int a)
    {
    #asm
    dec l
    ld a,l
    ld hl,&5a44
    ld c,(hl)
    ld (hl),1
    push bc
    push hl
    ld (&5a40),a
    call &15a
    pop hl
    pop bc
    ld (hl),c
    #endasm
    }
#endif

#ifdeclared open_scr
void open_scr(int num, int mode)
    {
    #asm
    pop de
    pop hl
    pop bc
    push bc
    push hl
    push de
    ld b,l
    call &157
    #endasm
    }

void display(int num)
    {
    #asm
    ld c,l
    call &100
    #endasm
    }

void close_scr(int num)
    {
    #asm
    ld c,l
    call &18d
    #endasm
    }
#endif

#ifdeclared palette, allpalette
void palette(int pos,int col)
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

void allpalette( char *p)
    {
    int i;
    for (i=0; i != 16; i++ )
        palette(i, *p++ );
    }
#endif


#ifdeclared triangle
void triangle(int x0,int y0,int x1,int y1,int x2,int y2)
    {
    moveto(x0,y0);
    drawto(x1,y1);
    drawto(x2,y2);
    drawto(x0,y0);
    }
#endif

#ifdeclared setover
void setover( int m)
    {
    #asm
    ld a,l
    ld (&5a4c),a
    ld (&5a55),a
    #endasm
    }
#endif

#ifdeclared getx, gety
int getx(void )
    {
    #asm
    ld hl,(&5a42)
    #endasm
    }

int gety(void )
    {
    #asm
    ld hl,(&5a41)
    ld h,0
    #endasm
    }
#endif

#ifdeclared fatpix
void fatpix(int a)
    {
    #asm
    ld a,l
    and 1
    ld (&5a44),a
    ld (&5a4d),a
    #endasm
    }
#endif

#ifdeclared roll, scroll
void scroll(int a,int b,int c,int d,int e,int f)
    {
    #asm
    xor a
    jr doroll_
    #endasm
    }

void roll(int a,int b,int c,int d,int e,int f)
    {
    #asm
    ld a,-1
doroll_:
    ld ix,0
    add ix,sp
    ld b,l
    ld c,(ix+4)
    ld d,(ix+6)
    ld e,(ix+8)
    ex af,af'
    ld l,(ix+12)
    ld a,191
    sub (ix+10)
    ld h,a
    ex af,af'
    call &14b
    #endasm
    }
#endif


#ifdeclared moveto
void moveto( int x,int y)
{
#asm
pop bc
pop de
pop hl
push hl
push de
push bc
ld a,191
sub e
ld (&5a41),a
ld (&5a42),hl
#endasm
}
#endif


#ifdeclared plot, putpixel
void plot (int x,int y)
{
#asm
pop de
pop bc     ; ARG 2
pop hl     ; ARG 1
push hl
push bc
push de
ld a,191
sub c
ld b,a
ld  c,l
call &139  ; volaj ROM
#endasm
}
#endif



#ifdeclared drawto
void drawto (int x,int y)
{
#asm
pop de
pop bc     ; ARG 2
pop hl     ; ARG 1
push hl
push bc
push de
ld a,191
sub c
ld b,a
ld  c,l
call &13f  ; volaj ROM
#endasm
}
#endif

#ifdeclared border
void border( int a)
    {
    #asm
    ld a,l
    and 15
    bit 3,a
    res 3,a
    jr  z,$+4
    set 5,a
    out (254),a
    ld  (&5c4b),a
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


#ifdeclared pen, paper
void paper(int color)
{
#asm
    call _uprcol
    ld (&5a51),a
    ld (&5a48),a
    ld (&5a30),a
    bit 3,a
    res 3,a
    jr  z,$+4
    set 5,a
    ld  (&5c4b),a
#endasm
}

void pen(int color)
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



