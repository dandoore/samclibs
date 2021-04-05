//    Sam Coupe prime demo
//    demo_prime.c
//
//    (C) 1995 RUMSOFT  
//

void clscr();
int printf(...);

int timer, prime;

unsigned gettime() { return *(unsigned *)0x5C78; }

void main()
{
register int n, s;

clscr();
timer= gettime();

for (n=3; n <= 200; n++ )
{
    prime=1;
    for (s=2;s<n;s++ )
       { if (n== (n/s)*s) {prime=0; break ;}   }
    if (prime) printf("%8d",n);
}
printf("\n\nTime = %d.%d secs",(gettime()-timer)/50,
        ((gettime()-timer)%50)/5);
}




