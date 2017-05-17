/* 9/15/99 JWB
 * no floating point, fixed point instead
 *
 */

/* This program enhances a 256-gray-level, 128x128 pixel image by applying
   global histogram equalization.

   This program is based on the routines and algorithms found in the book
   "C Language Algorithms for Disgital Signal Processing" by P. M. Embree
   and B. Kimble.

   Copyright (c) 1992 -- Mazen A.R. Saghir -- University of Toronto */
/* Modified to use arrays - SMP */


// height and width of the image
#define N 8
// number of gray-levels 
#define L 256
#include <stdio.h>
#include <stdlib.h>
#include "pliny_fill.h"

void read_from_file(char* filename, int img[N][N]) {
  FILE* image_file;
  int i;
  int j;

  image_file = fopen(filename, "r");

  if (image_file == NULL) {
    exit(-1);
  }

  for (i = 0; i < N; ++i) 
    for (j = 0; j < N; ++j) 
      fscanf(image_file, "%d", &img[i][j]);
}

void write_to_stdout(int img[N][N]) {
  int i;
  int j; 
  
  for (i = 0; i < N; ++i) 
    for (j = 0; j < N; ++j) 
      printf("%d ", img[i][j]);
}

int main(int argc, char** argv) {
  /* Implement histogram equalization */

  int cdf;
  int pixels;
  int i;
  int j;
  int foo;
  int image[N][N]; 
  int histogram[L];
  int gray_level_mapping[L];

  if (argc != 2)
    exit(-1);

  /* Get the original image */
  read_from_file(argv[1], image);

  /* Initialize the histogram array. */

  for (i = 0; i < L; i++)
    histogram[i] = 0;

  /* Compute the image's histogram */

   for (i = 0; i < N; i++) {
     for (j = 0; j < N; ++j) {
       __pliny_fill__(USE_VARS, histogram, image, i, j);
     }
   }

  /* Compute the mapping from the old to the new gray levels */
   
  /* fixed point with 20 binary decimal places */

  cdf = 0;
  pixels = N * N;
  for (i = 0; i < L; i++) {
    foo = (histogram[i] << 20);
    cdf += foo / pixels;
    gray_level_mapping[i] = ((255 * cdf) >> 20) & 0xff;
  }

  /* Map the old gray levels in the original image to the new gray levels. */
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; ++j) {
        image[i][j] = gray_level_mapping[image[i][j]];
    }
  }

  write_to_stdout(image);
}
