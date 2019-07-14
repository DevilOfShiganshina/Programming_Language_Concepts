/**
 * Assignment: Using the C programming language implement
 *             Heapsort in the manner described in class
 * 
 * Auhtor:     Tanjid A Shuhag (Tas)
 * Course:     Programming Language Concepts
 * Instructor: Dr. Kapleau
 * Due Date:   July 13th, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapfy(char *arr, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *)) {
  size_t child;
  while ((child = 2* parent) <= nelem) {
    if (child + 1 <= nelem && compar(arr + child * size, arr + (child + 1) * size) < 0) {
      child = child + 1;
    } if (compar(arr + parent * size, arr + child * size) < 0) {
      swap(arr + parent * size, arr + child * size, size);
      parent = child;
    } else { break; }
  }
}

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {
  char *arr;

  arr = malloc((size + 1) * nelem);
  memcpy(arr + size, base, nelem * size);
  
  for (int i = nelem / 2; i >= 1; i--) {
    heapfy(arr, nelem, size, i, compar);
  } for (int i = nelem; i > 1; i--) {
    swap(arr + size, arr + i * size, size);
    heapfy(arr, i - 1, size, 1, compar);
  }
  memcpy(base, arr + size, nelem * size);
  free(arr);
}