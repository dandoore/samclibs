//
//    Sam Coupe Standard C string library file
//    string.c
//
//    (C) 1995 RUMSOFT 22/10/95                                   
//

#ifdeclared strstr
char *strstr(char *s1, char *s2)
{
  int a,b;
  char *p;
  a=strlen(s1);
  p=s1;
  for (b=strlen(s2); b<a; -- a)
  {
    if (!strncmp(p++ , s2, b)) return -- p;
  }
  return 0;
}
#endif

#ifdeclared memcpy
memcpy(char *to, char *from, unsigned size)
{
#asm
pop af
pop bc
pop hl
pop de
push de
push hl
push bc
push af
ld a,b
or c
ret z
sbc hl,de
add hl,de
jr c,$+5
ldir
ret
dec bc
add hl,bc
ex de,hl
add hl,bc
ex de,hl
inc bc
lddr
#endasm
}
#endif

#ifdeclared strcpy
strcpy(char *s1, char *s2)
{
#asm
pop bc
pop hl
pop de
push de ; s1
push hl ; s2
push bc
ld c,e
ld b,d
strcpy_:
ld a,(hl)
ld (de),a
inc hl
inc de
and a
jr nz,strcpy_
ld l,c
ld h,b
#endasm
}
#endif

#ifdeclared strncpy
strncpy(char *a,char *b, unsigned c)
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
push hl
strncpy_:
ld a,b
or c
jr z,strncpy__
dec bc
ld a,(de)
ld (hl),a
inc hl
and a
jr z,strncpy_
inc de
jr strncpy_
strncpy__:
pop hl
#endasm
}
#endif

#ifdeclared strcat
strcat(char *s1,char *s2)
{
#asm
pop bc
pop de
pop hl
push hl
push de
push bc
ex de,hl
ld c,e
ld b,d
strcat_:
ld a,(de)
and a
jr z,strcat__
inc de
jr strcat_
strcat__:
ld a,(hl)
ld (de),a
and a
inc hl
inc de
jr  nz,strcat__
ld l,c
ld h,b
#endasm
}
#endif

#ifdeclared strncat
strncat(char *a1, char *b1,unsigned c1)
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
push hl
jr $+3

strncat_4:
inc hl
ld a,(hl)
and a
jr nz,strncat_4
strncat_1:
ld a,b
or c
jr z,strncat_3
dec bc
ld a,(de)
ld (hl),a
inc hl
and a
jr z,strncat_2
inc de
jr strncat_1
strncat_3:
ld (hl),0
strncat_2:
pop hl
#endasm
}
#endif

#ifdeclared memcmp
memcmp(char *s1, char *s2, unsigned n)
{
#asm
pop af
pop bc
pop hl
pop de
push de
push hl
push bc
push af

memcmp_:
ld a,b
or c
jr z,memcmp__
dec bc
ld a,(de)
sub (hl)
inc hl
inc de
jr z,memcmp_
ld h,0
ld l,a
cp 128
ret c
dec h
ret
memcmp__:
ld hl,0
#endasm
}
#endif

#ifdeclared strcmp
strcmp(char *s1, char *s2)
{
#asm
pop bc
pop hl
pop de
push de
push hl
push bc
strcmp_:
ld a,(de)
cp (hl)
jr nz,strcmp__
inc hl
inc de
and a
jr nz,strcmp_
ld hl,0
ret

strcmp__:
ld hl,1
ret nc
dec l
dec hl
#endasm
}
#endif

#ifdeclared strncmp
strncmp(char *a1, char *b1, unsigned c1)
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
strncmp_1:
ld a,b
or c
jp z,strncmp_2
dec bc
ld a,(de)
cp (hl)
jr nz,strncmp_2+4
inc hl
inc de
and a
jr nz,strncmp_1
strncmp_2:
ld hl,0
ret
ld hl,1
ret c
dec l
dec hl
#endasm
}
#endif


#ifdeclared stricmp
stricmp(char *s1, char *s2)
{
#asm
pop bc
pop hl
pop de
push de
push hl
push bc
stricmp_:
ld a,(hl)
cp "a"
jr c,$+8
cp "z"+1
jr nc,$+4
and &DF
ld c,a
ld a,(de)
cp "a"
jr c,$+8
cp "z"+1
jr nc,$+4
and &DF
cp c
jr nz,stricmp__
inc hl
inc de
and a
jr nz,stricmp_
ld hl,0
ret

stricmp__:
ld hl,1
ret nc
dec l
dec hl
#endasm
}
#endif

#ifdeclared strnicmp
strnicmp(char *a1, char *b1, unsigned c1)
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
strnicmp_1:
ld a,b
or c
jp z,strnicmp_2
dec bc
ld a,(hl)
cp "a"
jr c,$+8
cp "z"+1
jr nc,$+4
and &DF
push bc
ld c,a
ld a,(de)
cp "a"
jr c,$+8
cp "z"+1
jr nc,$+4
and &DF
cp c
pop bc
jr nz,strnicmp_2+4
inc hl
inc de
and a
jr nz,strnicmp_1
strnicmp_2:
ld hl,0
ret

ld hl,1
ret c
dec l
dec hl
#endasm
}
#endif


#ifdeclared memset
memset(char *addr, int val, unsigned size)
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
ld a,b
or c
ret z
dec bc
ld (hl),e
inc hl
jr $-6
#endasm
}
#endif

#ifdeclared strchr
strchr(char *s, int c)
{
#asm
pop bc
pop de
pop hl
push hl
pushh de
push bc

jr $+3
strchr_1:
inc hl
ld a,(hl)
and a
jr z,strchr_2
cp e
jr nz,strchr_1
ret
strchr_2:ld hl,0
#endasm
}
#endif

#ifdeclared strrchr
strrchr(char *a,int b)
{
#asm
pop af
pop de
pop hl
push hl
push de
push af
ld bc,0
jr $+4

inc hl
inc bc

ld a,(hl)
and a
jr nz,$-4
strrchrr_:
dec hl
ld a,b
or c
jr z,strrchr__
dec bc
ld a,(hl)
cp e
jr nz,strrchr_
ret
strrchr__:
ld  hl,0
#endasm
}
#endif

#ifdeclared memchr
char *memchr(char *from, int c, unsigned size)
{
#asm
pop de
pop bc
pop hl
ld a,l
pop hl
push hl
push hl
push bc
push de
cpir
dec hl
jp nz,nula
#endasm
}
#endif

#ifdeclared stpcpy
char *stpcpy(char *d, char *s)
{
  while (*s) *d++ = *s++ ;
}
#endif

#ifdeclared strlwr
char *strlwr(char *s)
{
  while (*s=tolower(*s++ ));
}
#endif

#ifdeclared strupr
char *strupr(char *s)
{
  while (*s=toupper(*s++ ));
}
#endif

#ifdeclared strset
char *strset(char *s, int ch)
{
  char *p;
  p=s;
  while (*p) *p++ = ch;
  return s;
}
#endif

#ifdeclared strnset
char *strnset(char *s, int ch, unsigned w)
{
  char *p;
  p=s;
  while (w-- ) *p++ = ch;
  return s;
}
#endif



