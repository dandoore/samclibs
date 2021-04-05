//
//    Sam Coupe Standard C string headers
//    string.h
//
//    (C) 1995 RUMSOFT 13.11.1995                                      
//

#ifndef STRING
extern void * memcpy(char *a,char *b,unsigned c);
extern char * strcpy(char *a,char *b);
extern char * strncpy(char *a,char *b,unsigned c);
extern char * strcat(char *a,char *b);
extern char * strncat(char *a,char *b,unsigned c);
extern int memcmp(char *a,char *b,unsigned c);
extern char * strcmp(char *a,char *b);
extern char * strnicmp(char *a,char *b,unsigned c);
extern char * stricmp(char *a,char *b);
extern char * strncmp(char *a,char *b,unsigned c);
extern char * memchr(char *s, int c, unsigned width);
extern char * stpcpy(char *dest, const char *src);
extern char * strlwr(char *s);
extern char * strset(char *s, int ch);
extern char * strnset(char *s, int ch, unsigned w);
extern char * strupr(char *s);
extern char * strstr(char *a,char *b);
extern void * memset(char *a,int b,unsigned c);
extern char * strchr(char *a,int b);
extern char * strrchr(char *a,int b);
#endif



