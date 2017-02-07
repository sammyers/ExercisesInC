/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	   array[i] = 42;
    }
    return array; // Compiler warns about returning address of stack memory
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	   array[i] = i;
    }
}

/* It looks like this program is supposed to create an empty array, print the pointer,
 * fill it with 42's, and assign a pointer to it to the 'array' variable.
 * It looks like it's trying to do the same thing again but with numbers 1-5.
 * Finally, it looks like the program is intended to print the array returned by foo.
 *
 * The program actually outputs the first two pointers and then a lot of nonsense.
 * This happens because the memory allocated to the array on the stack doesn't stick around,
 * so the pointer that gets returned doesn't point to anything reliable.
 *
 * After commenting out the print statements, the program gives about the same garbage output.
 * (four zeros and a really large number, minus the pointers)
 */
int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	   printf("%d\n", array[i]);
    }

    return 0;
}
