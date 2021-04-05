//
//    Sam Coupe standard C system function
//    system.c
//
//    (C) 1995 RUMSOFT                                   
//

#ifdeclared disable
void disable()
{
#asm
di
#endasm
}
#endif

#ifdeclared enable
void enable()
{
#asm
ei
#endasm
}
#endif

#ifdeclared inp
unsigned inp(int port)
{
#asm
ld c,l
ld b,h
in l,(c)
ld h,0
#endasm
}
#endif

#ifdeclared outp
void outp(int port, int value)
{
#asm
pop de
pop hl
pop bc
push bc
push hl
push de
out (c),l
ld l,c
ld h,0
#endasm
}
#endif

#ifdeclared escape
int escape()
{
#asm
ld hl,0
ld a,&f7
in a,(&f9)
and 32
ret nz
inc l
#endasm
}
#endif

#ifdeclared avail
extern char * MEMPTR_;

unsigned avail(int abt) {
if (0xFF00 < MEMPTR_) {
  if (abt) abort(1);
  return (NULL);
  }
return (0xFF00-MEMPTR_);
}

#endif

#ifdeclared poke
void poke(unsigned a,int b)
{
#asm
pop bc
pop de
pop hl
push hl
push de
push bc
ld (hl),e
#endasm
}
#endif

#ifdeclared dpoke
void dpoke (unsigned a,int b)
{
#asm
pop bc
pop de
pop hl
push hl
push de
push bc
ld (hl),e
inc hl
ld (hl),d
#endasm
}
#endif

#ifdeclared peek
unsigned char peek (unsigned a)
{
#asm
ld l,(hl)
ld h,0
#endasm
}
#endif

#ifdeclared dpeek
unsigned dpeek (unsigned a)
{
#asm
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
#endasm
}
#endif

#ifdeclared callcode
void callcode(int a,int bc,int de,int hl,unsigned addr)
{
#asm
ld (adrcall_+1),hl
push ix
ld ix,0
add ix,sp
  ld l,(ix+4)
  ld h,(ix+5)
  ld e,(ix+6)
  ld d,(ix+7)
  ld c,(ix+8)
  ld b,(ix+9)
  ld a,(ix+11)
  and a
adrcall_:call 0
  pop ix
#endasm
}
#endif

#ifdeclared pause
void pause(unsigned c)
{
#asm
ei
ld a,h
or l
ret z
halt
dec hl
ld a,&7f
in a,(254)
rrca
ret nc
jr $-11
#endasm
}
#endif

#ifdeclared gettime
unsigned gettime()
{
#asm
ld hl,(&5c78)
#endasm
}
#endif

#ifdeclared getsp
unsigned getsp()
{
#asm
ld hl,0
add hl,sp
#endasm
}
#endif


