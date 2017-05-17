#include <stdio.h>
#include <stdlib.h>

static int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static int size = 10;

int binSearch(int element) {
    int min = 0,
        max = size - 1;

    while (min <= max) {
        int mid = (min + max) / 2;
        if (element == data[mid])
             return mid;
        else if (element < data[mid])
             max = mid - 1;
        else min = mid + 1;
    }

    return -1;
}

