// https://github.com/ygorshenin/ac_sorting/blob/d3da4f3907a90c9f5e6cc05ab0ad61855b0a42a7/src/insertion_sort.c

#include <stddef.h>

void insertion_sort(size_t n, int *array) {
  size_t i, j;
  int t;

  if (n < 2)
    return;

  for (i = 1; i < n; ++i) {
    j = i;
    t = array[i];

    while (j > 0 && array[j - 1] > t) {
      array[j] = array[j - 1];
      --j;
    }
    array[j] = t;
  }
}