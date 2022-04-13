#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*
 * 17. Letter Combinations of a Phone Number
 * Given a digit string, return all possible 
 * letter combinations that the number could represent.
 *
 * Runtime: 3ms
 */


char* letters = " _______abc_def_ghi_jkl_mno_pqrstuv_wxyz";
int lens[10] = {1, 0, 3, 3, 3, 3, 3, 4, 3, 4};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
  if(digits[0] == '\0') return NULL;

  /*
  * DECLARATIONS
  */
  int num, numDigits, i, k, idx;
  int offset, totalSize, repSize;
  char** ret;

  /*
  * COMPUTE TOTAL SIZE
  */
  totalSize = 1;
  for(numDigits = 0; digits[numDigits] != '\0'; numDigits++) {
    num = digits[numDigits] - 48;
    if(num < 2) return NULL;

    totalSize *= lens[num];
  }

  /*
  * ALLOCATE RETURN ARRAY MEMORY
  */
  repSize = *returnSize = totalSize;
  ret = (char**) malloc(sizeof(char*) * totalSize);
  for(k = 0; k < totalSize; k++) {
    ret[k] = (char*) malloc(sizeof(char) * (numDigits+1));
    ret[k][numDigits] = '\0';
  }

  /*
  * BUILD STRINGS
  */
  for(i = 0; i < numDigits; i++) {
    offset = -1;
    num = digits[i] - 48;
    repSize = repSize / lens[num];

    for(k = 0; k < totalSize; k++) {
      if(k % repSize == 0) {
        offset += 1;
      }
      idx = (num * 4) + (offset % lens[num]);
      ret[k][i] = letters[idx];
    }
  }
  return ret;  
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./phone <string>\n");
    return 0;
  }

  int retSize = 0;
  char **combos = letterCombinations(argv[1], &retSize);

  int i = 0;
  for(; i < retSize; i++) {
    printf("%s\n", combos[i]);
    free(combos[i]);
  }
  free(combos);
  return 0;
}