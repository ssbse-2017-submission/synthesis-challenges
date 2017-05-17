// https://github.com/wzh14/gr/blob/39375a4c7f769f83f846222ba5beb80fec5863f2/study/program/algorithm/sort/InsertionSort/InsertionSort.h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void InsertionSort( ElementType A[], int N )
{
  int j, P;
  ElementType Tmp;

  for( P = 1; P < N; P++ ){
    Tmp = A[ P ];
    for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
      A[ j ] = A[ j - 1 ];

    A[ j ] = Tmp;
  }
}