// https://github.com/tsiangleo/clrs/blob/e4f5e67bebecbad6f05c19b44444bebfe00ea361/02/insertion_sort/insertion_sort.c

#include <stdlib.h>
#include <assert.h>


void insertion_sort(int a[],int size)
{
    int i,j,key;

    assert(a != NULL && size > 0);
    if(size < 2)
        return;

    for(i = 1;i < size;i++)
    {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key)//asend order
        {
            a[j+1] = a[j];
            j --;

        }
        a[j+1] = key;

#ifdef DEBUG
        print_array(a,size);
#endif
    }
}