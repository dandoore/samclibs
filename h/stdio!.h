//
//    Sam Coupe Standard Small C definitions - for SMART RUNTIME VERSION
//    stdio!.h
//
//    (C) 1995 RUMSOFT 10.10.95//
                                             
#ifndef STDIO

#define STDIO     1
#define EOF     (-1)
#define ERR     (-2)
#define YES       1
#define NO        0
#define NULL      0
#define CR       13
#define LF       10
#define SPACE   ' '
#define stderr    0
#define stdin     0
#define stdout    2
#define stdprn    3

/*
** These function prototypes is built up in the runtime file
*/

extern void putchar(int c);
extern void putc(int c);
extern void fputs(char *s, int strm);
extern void puts(char *s);
extern void fputc(int c, int strm);

extern int getchar( void );
extern int getc( void );
extern int getche( void ); // as per getch(), but with echo
extern int getch( void );
extern int fgetc(int strm);
extern char * fgets(char *string, int max, int stream);
extern char * gets(char *string);
extern int kbhit( void );

extern void stream(int stream);
extern void print(char *s);
extern void at(int line, int column);

extern int printf(...);   // this six functions is VARIADIC !!!

extern char * input(int line, int column, int max);

extern char * MEMPTR_;    // pointer to first free byte

extern char * skip(char *string);
extern char * itoa(int value, char *string, int radix);
extern char * itou(int value, char *string, int radix);
extern int atoi(char *s, int radix);

extern void exit(int c);
extern void * calloc(unsigned n, unsigned size);
extern void * malloc(unsigned size);
extern void * free(unsigned block);
extern void clscr(void );
#define clrscr() clscr()
#endif


