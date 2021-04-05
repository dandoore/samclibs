//
//    Sam Coupe standard C library
//    stdlib.c
//
//    (C) 1995 RUMSOFT - Last update: 22.08.95
//                                       

#ifdeclared abort
void abort(int c)
{
#asm
ld ($+4),hl
rst 8
db 0
#endasm
}
#endif

#ifdeclared abs
unsigned abs(int a)
{
#asm
bit 7,h
ret z
ex de,hl
ld hl,0
and a
sbc hl,de
#endasm
}
#endif


#ifdeclared atexit
extern int atexit_;
void atexit(int (*fnc)())
    {
    atexit_=fnc;
    }
#endif


#ifdeclared beep
void beep (int dlzka,int vyska)
{
#asm
pop bc
pop de
pop hl
push hl
push de
push bc
call &16f
#endasm
}
#endif

#ifdeclared gdump, tdump
void gdump ()
{
#asm
call &160
#endasm
}

void tdump ()
{
#asm
call &15d
#endasm
}
#endif

#ifdeclared max
int max(int a,int b)
    {
    #asm
    pop bc
    pop de
    pop hl
    push hl
    push de
    push bc
    and a
    sbc hl,de
    add hl,de
    ret nc
    ex de,hl
    #endasm
    }
#endif


#ifdeclared min
int min(int a,int b)
    {
    #asm
    pop bc
    pop de
    pop hl
    push hl
    push de
    push bc
    and a
    sbc hl,de
    add hl,de
    ret c
    ex de,hl
    #endasm
    }
#endif


#ifdeclared sort

int krok, ii, jj;

int sort(char * from,
int off, int s, int items;
int (*compare)(), int (*swap)())
{

    for (krok = (items)/2; krok > 0; krok/= 2)
        for (ii = krok; ii < items; ii++ )
            for (jj = ii-krok; jj >= 0; jj -= krok)
{
if ((*compare)(from+(jj*s)+off,from+(jj*s)+(krok*s)+off)<= 0)
   break ;
(*swap)(from+(jj*s), from+(jj*s)+(krok*s));
}
}
#endif

#ifdeclared swap
void swap(int width, char *s1, char *s2)
{
#asm
pop af
pop bc
pop de
pop hl
push hl
push de
push bc
push af
swap_:ld a,(de)
ldi
dec hl
ld (hl),a
inc hl
jp pe,swap_
#endasm

}
#endif


#ifdeclared sound
sound(int a)  // this is variadic function
{
    int count, *data;
    data=&a;

    for (count=CCARGC(); count <= 0; count -= 2)
         sound1 (*data++ ,*data++ );
}

sound1(int port, int data)
{
    #asm
    pop bc
    pop de
    pop hl
    push hl
    push de
    push bc
    ld bc,&1ff
    out (c),e
    dec b
    out (c),l
    #endasm
}
#endif


#ifdeclared is512
is512() {
#asm
ld hl,(&5cb4)
ld h,0
ld de,15
and a
sbc hl,de
#endasm
}
#endif


#ifdeclared nosound
nosound() {
#asm
ld e,&1c
ld bc,&1ff
xor a
no_01:
out (c),e
dec b
out (c),a
inc b
dec e
jp p,no_01
#endasm
}
#endif


#ifdeclared rand, srand
void srand(int a) {
#asm
ld a,h
or l
jr nz,$+5
ld hl,(&5c78)
ld (&5c76),hl
#endasm
}

int rand() {
#asm
ld hl,(&5c76)
ld a,r
add l
ld l,a
sub h
ld h,a
add hl,bc
add hl,hl
add hl,bc
ld de,(&5c78)
add hl,de
ld (&5c76),hl
#endasm
}
#endif


#ifdeclared outprn
void outprn(int c) {
#asm
ld a,l
call &181
#endasm
}
#endif


