#include <stdio.h>
#include <stdlib.h>

/*
 * 389. Find the Difference
 * Given two strings s and t which consist of only lowercase letters.
 * String t is generated by random shuffling string s
 * and then add one more letter at a random position.
 * Find the letter that was added in t. 
 *
 * Runtime: 0ms
 */

char findTheDifference(char* s, char* t) {
  int cs[256], ct[256];
  int i = 0;
  for(; i < 256; i++) {
    cs[i] = ct[i] = 0;
  }

  int idx;
  for(idx = 0; s[idx] != '\0'; idx++) cs[s[idx]] += 1;
  for(idx = 0; t[idx] != '\0'; idx++) ct[t[idx]] += 1;

  char ret = s[0];
  for(idx = 0; idx < 256; idx++) {
    if( cs[idx] != ct[idx] ) {
      ret = (char) idx;
      break;
    }
  }
  return ret;
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./find_diff <str1> <str2>\n");
    return 0;
  }

  char diff = findTheDifference(argv[1], argv[2]);
  printf("%c\n", diff);
  return 0;
}