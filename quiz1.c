/* quiz1.c
 * Prof. Harlan Russell
 * ECE 2230 Fall 2024
 *
 * This is an example for finding errors with valgrind.  Do
 *     gcc -g -Wall quiz1.c -o quiz1
 *     valgrind --leak-check=full ./quiz1
 *
 * You can fix the errors anyway you like.  Suggestions are below
 */


#include <stdlib.h>


#define SIZE 10


void fun(void)  {
    int *x = (int *) malloc(SIZE * sizeof(int));


    x[SIZE] = 0; // invalid write.  Perhaps change index to SIZE-1.  Or set values to all positions 
                 // from 0 to SIZE-1.  Or use calloc instead of malloc.


    if (x[0] == 0) x[0] = 1;  // if x[0] not initialised then get
                              // conditional jump or move depends on unititialised values

    // when program ends get
    //   40 bytes in 1 blocks are definitely lost in loss record 1 or 1
    // Perhaps free(x).  Or return x and free in main.
    free(x);
}


int main(void)
{
    fun();
    return 0;
}

