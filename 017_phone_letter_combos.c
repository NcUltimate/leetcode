#include <stdio.h>
#include <math.h>

/*
 * 17. Letter Combinations of a Phone Number
 * Given a digit string, return all possible 
 * letter combinations that the number could represent.
 *
 * Runtime: 16ms
 */

char** letters = {
  {' ', '^', '^', '^'},
  {'^', '^', '^', '^'},
  {'a', 'b', 'c', '^'},
  {'d', 'e', 'f', '^'},
  {'g', 'h', 'i', '^'},
  {'j', 'k', 'l', '^'},
  {'m', 'n', 'o', '^'},
  {'p', 'q', 'r', 's'},
  {'t', 'u', 'v', '^'},
  {'w', 'x', 'y', 'z'}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
  int l = 0;
  for(; digits[l] != '\0'; l++);
  char** result = (char*)malloc(sizeof(char*) * pow(4, l));

  int i = 0;
  for(; digits[i] != '\0'; i++) {
    
  }
  return NULL;   
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
  }
  return 0;
}