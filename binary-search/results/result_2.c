/* There is a minor bug in the function main - that it can not read
   integers properly */

#include <stdio.h>
#define MAXLIM 1000 /* maximum limit of array */

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {   /* found match */
      return mid;
    }
  }
  return -1;    /* no match */
}

/*************************************************/
/* Note:
   Since main() always returns int, it's good style to show this explicitly.
   Therefore adding "return 0;" is a also good practice.
   For compiling with GNU C, use 
   gcc -W -Wall -ansi -pedantic <fileName.c>
*/
