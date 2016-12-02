#include <stdio.h>
#include <stdlib.h>

/*
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * Runtime: 0ms
 */
 
char* longestCommonPrefix(char** strs, int strsSize) {
  if(strsSize == 0) return "";
  if(strsSize == 1) return strs[0];

  int c = 0;
  while(1) {
    int idx = 0;
    char ch = strs[0][c];

    while( idx != strsSize ) {
      if( strs[idx][c] == '\0') return strs[idx];

      if( strs[idx][c] != ch) {
        strs[idx][c] = '\0';
        return strs[idx];
      }
      idx++;
    }
    c++;
  }
  return "";
}

int main(int argc, char** argv) {
  char* prefix = longestCommonPrefix(&argv[1], argc - 1);
  printf("'%s'\n", prefix);
  return 0;
}