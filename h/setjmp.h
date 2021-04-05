//
//    Sam Coupe LongJmp implementation - ANSI
//    setjmp.h
//
//    (C) 1995 RUMSOFT
//

typedef struct { int _sp,_pc; } jmp_buf;

/* setjmp() is used with longjmp() for non-local gotos. */

extern int setjmp(jmp_buf *jmpbuf);

/* longjmp() in conjuction with setjmp(), provides a machanism
** for non-local gotos. To use this facility, setjmp() should
** be called with a poiter to jmp_buf argument in some outer
** level function. The call from setjmp() will return 0. To
** return to this level of execution, longjmp() may be called
** with the same jmp_buf argument from an inner level of execu-
** tion. NOTE however that the function which called setjmp()
** must still be active when longjmp() is called. Breach of this
** rule will cause disaster,due to the use of a stack containing
** invalid data. The val argument to longjmp() will be the value
** apperently returned from the setjmp(). This should normally
** be non-zero, to distinguish it from the genuine sejmp() call.
   for EXAMPLE :

   #include "setjmp.h"

   static jmp_buf jb_err;

   main()
   {
      if (setjmp(jb_err) {
        printf("An error occured");
        exit(1);
      }
      afunc();
   )

   afunc()
   {
      if (do _whatever() != 0) longjmp(jb_err, 1);
      if (do _something_else () != 0) longjmp(jb_err, 2);
   }

** The calls to longjmp() above will never return ; rather the
** call to setjmp() will appear to return , but with a return
** value equal to the argument supplied to longjmp(). */


extern void longjmp(jmp_buf *jmpbuf, int val);

#asm
setjmp: POP  BC
        PUSH HL
        LD   HL,2
        ADD  HL,SP
        LD   E,L
        LD   D,H
        POP  HL
        LD   (HL),E     ; SP
        INC  HL
        LD   (HL),D
        INC  HL
        LD   (HL),C     ; PC
        INC  HL
        LD   (HL),B
        PUSH BC
        LD   HL,0
        RET
;
longjmp:POP  BC
        POP  BC
        POP  HL
        LD   E,(HL)
        INC  HL
        LD   D,(HL)
        INC  HL
        LD   A,(HL)     ; PC
        INC  HL
        LD   H,(HL)
        LD   L,A
        EX   DE,HL
        LD   SP,HL
        LD   L,C
        LD   H,B
        PUSH DE
        RET
;
#endasm


