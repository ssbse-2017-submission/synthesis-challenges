// Factored, but otherwise this is the example from:
// http://www.programmingsimplified.com/c/source-code/c-program-binary-search
#include <stdio.h>

// Returns the index into array[] that value search was found at.
// Returns -1 if not found.
int bin_search(int n, int array[100], int search)
{
   int c, first, last, middle;
  
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
     return middle;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   return -1;
}
 
