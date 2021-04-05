//
//  Standard SAM's ctypes headers file
//  ctype.h
//
//  (C) RUMSOFT 1994 04.10.94
//

#ifndef CTYPE
#define CTYPE
extern char isalpha(int c);
extern char isupper(int c);
extern char islower(int c);
extern char isxdigit(int c);
extern char ispunct(int c);
extern char isalnum(int c);
extern char isprint(int c);
extern char isgraph(int c);
extern char iscntrl(int c);
extern char isascii(int c);
extern char toupper(int c);
extern char tolower(int c);
extern char toascii(int c);
#endif



