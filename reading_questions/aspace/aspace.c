/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void foo()
{
    int local = 5;
    printf ("Address of local is %p\n", &local);
}

int main ()
{
    int local = 5;
    void *p = malloc(15);
    void *p2 = malloc(15);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    foo();
    printf ("Address of p is %p\n", p);
    printf ("Address of p2 is %p\n", p2);
    
    return 0;
}
