//
//    Sam Coupe standard 'C' string <-> number conversion
//    string2.c
//
//    (C) 1995 RUMSOFT - Last update: 07.01.95
//

#ifdeclared itoo
/*
** itoo -- convert nbr to octal string of length sz
**         right adjusted, blank filled; returns str
**
**        if sz > 0 terminate with null byte
**        if sz = 0 find end of string
**        if sz < 0 use last byte for data
*/
itoo(int nbr, char str[], int sz ) {
  int digit;
  if (sz>0) str[-- sz]=0;
  else if (sz<0) sz = -sz;
  else while (str[sz]!= 0) ++ sz;
  while (sz) {
    digit=nbr&7; nbr=(nbr>> 3)&8191;
    str[-- sz]=digit+48;
    if (nbr== 0) break ;
    }
  while (sz) str[-- sz]=' ';
  return str;
  }
#endif

#ifdeclared itou
/*
** itou -- convert nbr to unsigned decimal string of length sz
**         right adjusted, blank filled; returns str
**
**        if sz > 0 terminate with null byte
**        if sz = 0 find end of string
**        if sz < 0 use last byte for data
*/
itou(int nbr, char str[], int sz ) {
  int lowbit;
  if (sz>0) str[-- sz]=NULL;
  else if (sz<0) sz = -sz;
  else while (str[sz]!= NULL) ++ sz;
  while (sz) {
    lowbit=nbr&1;
    nbr=(nbr>> 1)&32767; /*divide by 2*/
    str[-- sz]=((nbr%5<< 1)+lowbit+'0');
    if ((nbr=nbr/5)== 0) break ;
    }
  while (sz) str[-- sz]=' ';
  return str;
  }
#endif

#ifdeclared itox
/*
** itox -- convert nbr to hex string of length sz
**         right adjusted, blank filled; returns str
**
**        if sz > 0 terminate with null byte
**        if sz = 0 find end of string
**        if sz < 0 use last byte for data
*/
itox(int nbr, char str[], int sz ) {
  int digit, offset;
  if (sz>0) str[-- sz]=0;
  else if (sz<0) sz = -sz;
  else while (str[sz]!= 0) ++ sz;
  while (sz) {
    digit=nbr&15; nbr=(nbr>> 4)&4095;
    if (digit<10) offset=48; else offset=55;
    str[-- sz]=digit+offset;
    if (nbr== 0) break ;
    }
  while (sz) str[-- sz]=' ';
  return str;
  }
#endif

#ifdeclared itod
/*
** itod -- convert nbr to signed decimal string of width
**         right adjusted, blank filled; returns str
**
**        if sz > 0 terminate with null byte
**        if sz = 0 find end of string
**        if sz < 0 use last byte for data
*/
itod(int nbr, char str[], int sz ) {
  char sgn;
  if (nbr<0) {nbr = -nbr; sgn='-';}
  else sgn=' ';
  if (sz>0) str[-- sz]=NULL;
  else if (sz<0) sz = -sz;
  else while (str[sz]!= NULL) ++ sz;
  while (sz) {
    str[-- sz]=(nbr%10+'0');
    if ((nbr=nbr/10)== 0) break ;
    }
  if (sz) str[-- sz]=sgn;
  while (sz>0) str[-- sz]=' ';
  return str;
  }
#endif



#ifdeclared otoi
/*
** otoi -- convert unsigned octal string to integer nbr
**          returns field size, else ERR on error
*/
otoi(char *octstr, int *nbr ) {
  int d, t; d=0;
  *nbr=0;
  while ((*octstr>'0')&(*octstr<= '7')) {
    t=*nbr;
    t=(t<< 3) +(*octstr++ - '0');
    if ((t>= 0)&(*nbr<0)) return ERR;
    d++ ; *nbr=t;
    }
  return d;
  }
#endif

#ifdeclared utoi
/*
** utoi -- convert unsigned decimal string to integer nbr
** Returns field size if successful, else ERR.
*/
utoi(char *decstr, int *nbr ) {
  int d , t ; d=0;
  *nbr = 0;
  while ((*decstr>= '0')&(*decstr<= '9')) {
    t=*nbr; t=(10*t) + (*decstr++ - '0');
    if ((t>= 0)&(*nbr<0)) return ERR;
    d++ ; *nbr=t;
    }
  return d;
  }
#endif

#ifdeclared xtoi
/*
** xtoi -- convert hex string to integer nbr
** Returns field size if successful, else ERR.
*/
xtoi(char *hexstr , int *nbr ) {
  int d, t ; d=0;
  *nbr = 0;
  while (1) {
    if ((*hexstr>= '0')&(*hexstr<= '9')) t=48;
    else if ((*hexstr>= 'A')&(*hexstr<= 'F')) t=55;
    else if ((*hexstr>= 'a')&(*hexstr<= 'f')) t=55;
    else break ;
    if (d<4) ++ d; else return ERR;
    *nbr=*nbr<< 4;
    *nbr=*nbr+(*hexstr++ )-t;
    }
  return d;
  }
#endif

#ifdeclared dtoi
/*
** dtoi -- convert signed decimal string to integer nbr
**        returns field length, else ERR on error
*/
dtoi(char *decstr, int *nbr ) {
  int len, s;
  if ((*decstr)== '-') {s=1; ++ decstr;} else s=0;
  if ((len=utoi(decstr, nbr))<0) return (ERR);
  if (*nbr<0) return (ERR);
  if (s) {*nbr = -*nbr; return (++ len);} else return (len);
  }
#endif

#ifdeclared reverse
/*
** Reverse a string in place.
*/
reverse(char *s) {
  char *j;
  int c;
  j = s + strlen(s) -1;
  while (s < j) {
    c = *s;
    *s++ = *j;
    *j-- = c;
    }
  }
#endif

#ifdeclared left
/*
** left -- left adjust and terminate a string
*/
left(char *str ) {
  char *str2;
  str2=str;
  while (*str2== ' ') ++ str2;
  while (*str++ = str2++ );
  }
#endif


