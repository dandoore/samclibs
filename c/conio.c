//
//    Sam Coupe standard C console input/output
//    conio.c
//
//    (C) 1995 RUMSOFT - Last update: 01.10.95
//

#ifdeclared over
over(int a)
{
    putchs(21,a);
}
#endif


#ifdeclared bright,tab,flash,inverse
bright(int a)
{
    putchs(19,a);
}

flash(int a)
{
    putchs(18,a);
}

inverse(int a)
{
    putchs(20,a);
}

tab(int a)
{
    putchs(23,a);
}
#endif

#ifdeclared flash,bright,inverse,over,tab
putchs(int a,int b)
{
    putch (a);
    putch (b);
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


#ifdeclared border
border(int a)
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


#ifdeclared blocks
void blocks(int a)
{
#asm
ld a,l
and  1
xor  1
ld (&5a34),a
#endasm
}
#endif

#ifdeclared window
void window(int a,int b,int c,int d)
{
#asm
pop hl
exx
pop bc
ld b,c
pop hl
ld c,l
pop hl
ld e,l
pop hl
ld d,l
ld (&5a38),de
ld (&5a3a),bc
ld (&5a56),de
ld (&5a58),bc
ld h,l
ld l,d
ld (&5a6c),hl
push bc
push bc
push bc
push bc
exx
push hl
#endasm
}
#endif



