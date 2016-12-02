#include <stdlib.h>
#include <stdio.h>

/*
 * 4. Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  return 0.0;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./sorted_median a1 ... an %% b1 ... bn\n");
    return 0;
  }

  int i=0;
  int mod = 0;
  for(; i < argc; i++) {
    if( argv[i][0] == '%' ) mod = i;
  }

  if( !mod ) {
    printf("Error: %% must be specified between lists.\n");
    printf("Usage: ./sorted_median a1 ... an %% b1 ... bn\n");
    return 0;
  }

  int len1 = mod - 1;
  int len2 = argc - mod - 1;
  int ary1[len1];
  int ary2[len2];
  for( i = 0; i < argc - 1; i++ ) {
    int argv_idx = i + 1;
    if( argv_idx == mod ) continue;

    if( argv_idx < mod ){
      ary1[i] = atoi(argv[argv_idx]);
    } 
    else {
      ary2[i - len1 - 1] = atoi(argv[argv_idx]);
    }
  }

  double median = findMedianSortedArrays(ary1, len1, ary2, len2);
  printf("%f\n", median);
  return 0;
}
  

