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
    for(j=0; j<n; j++)
    {
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i]>key)
        {
            __pliny_fill__(ALL_VARS);
            i--;
        }
        arr[i+1] = key;
    }
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
