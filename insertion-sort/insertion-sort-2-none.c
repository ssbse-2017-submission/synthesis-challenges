// https://github.com/abhiramravi/Third-Semester---Programming-Lab/blob/b4d30865595c24ecd50c970af77cfdaf841d975f/finaleval/insertion_sort/insertion_sort.c

/*
 * Abhiram CS10B060
 * Insertion sort
 */

#include <stdio.h>
#include <stdlib.h>
#include "pliny_fill.h"

void insertion_sort( int n, int* arr )
{
    int j;
    int i;
    int key;
    __pliny_fill__(ALL_VARS);
}

int main(int argc, char** argv)
{
    int size = argc - 1;
    int data[size];
    for(int i=0; i<size; ++i)
    {
        data[i] = atoi(argv[i+1]);
    }
    insertion_sort(size, data);
    for(int i=0; i<size; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
