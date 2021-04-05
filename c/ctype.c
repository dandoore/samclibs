//
//    Sam Coupe standard C type
//    ctype.c
//
//    (C) 1995 RUMSOFT - Last update: 21.08.95
//

#ifdeclared isalpha

isalpha(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp "A"
ret c
cp "z"+1
ret nc
ld l,a
cp "a"
ret nc
cp "Z"+1
ret c
ld l,0
#endasm
}

#endif


#ifdeclared isupper

isupper(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp "A"
ret c
cp "Z"+1
ret nc
ld l,a
#endasm
}

#endif


#ifdeclared islower

islower(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp "a"
ret c
cp "z"+1
ret nc
ld l,a
#endasm
}

#endif


#ifdeclared isxdigit
isxdigit(int c)
{



#asm
call isdigit
inc l
dec l
ret nz
cp "A"
ret c
cp "f"+1
ret nc
ld l,a
cp "F"+1
ret c
cp "a"
ret nc
ld l,0
#endasm
}
#endif


#ifdeclared ispunct
ispunct(int c)
{
#asm
ld a,h
and a
ld a,l
ret nz
cp "."
ret z
cp ":"
ret z
cp ";"
ret z
cp ","
ret z
cp "\"
ret z
cp "/"
ret z
cp "-"
ret z
cp "!"
ret z
cp "?"
ret z
ld l,0
#endasm
}

#endif


#ifdeclared isalnum

isalnum(int c)
{
#asm
call isdigit
inc l
dec l
ret nz
ld l,a
call isalpha
#endasm
}

#endif


#ifdeclared isprint

isprint(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp " "
ret c
cp 128
ret nc
inc l
#endasm
}
#endif


#ifdeclared iscntrl

iscntrl(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp " "
ret nc
ld l,a
#endasm
}
#endif


#ifdeclared isascii

isascii(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp 128
ret nc
inc l
#endasm
}

#endif


#ifdeclared isgraph

isgraph(int c)
{
#asm
ld a,h
and a
ld a,l
ld hl,0
ret nz
cp "!"
ret c
cp 128
ret nc
inc l
#endasm
}

#endif

#ifdeclared toupper

toupper(int a)
{
#asm
ld a,h
and a
ret nz
ld a,l
cp "a"
ret c
cp "z"+1
ret nc
res 5,l
#endasm
}
#endif

#ifdeclared tolower

tolower(int c)
{
#asm
ld a,h
and a
ret nz
ld a,l
cp "A"
ret c
cp "Z"+1
ret nc
set 5,l
#endasm
}

#endif

#ifdeclared toascii

toascii (int c)
{
#asm
ex de,hl
ld hl,127
call CCAND
#endasm
}
#endif


