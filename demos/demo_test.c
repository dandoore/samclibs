//
//    The test of speed for auto ,register and static variables..
//    demo_test.c
//
//    (C) 1995 RUMSOFT 7.9.1995                                   
//

unsigned time;
char pole[1000];

unsigned gettime(void )
{
    return (*(int *)0x5C78);
}

int test0()
{
    auto int a,b;
    time = gettime();

    a=0;
    while (a != 100)
    {
        b=0;
        while (b != 1000)
        {
            pole[b++ ]=0;
        }
        ++ a;
    }
    return (gettime()-time);
}

int test1()
{
    register int a,b;
    time = gettime();

    a=0;
    while (a != 100)
    {
        b=0;
        while (b != 1000)
        {
            pole[b++ ]=0;
        }
        ++ a;
    }
    return (gettime()-time);
}

int test2()
{
    static int a1,b1;
    time = gettime();

    a1=0;
    while (a1 != 100)
    {
        b1=0;
        while (b1 != 1000)
        {
            pole[b1++ ]=0;
        }
        ++ a1;
    }
    return (gettime()-time);
}

main()
{
    printf("Test0 = %u sec.\n", test0()/50);
    printf("Test1 = %u sec.\n", test1()/50);
    printf("Test2 = %u sec.\n", test2()/50);
}

