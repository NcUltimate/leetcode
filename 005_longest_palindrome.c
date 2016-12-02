#include <stdlib.h>
#include <stdio.h>

/*
 * 5. Longest Palindromic Substring
 * Given a string S, find the longest palindromic substring in S. 
 *
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 *
 * Runtime: 24ms
 */

char* longestPalindrome(char* s) {
  if(s[0] == '\0') return "";
  if(s[1] == '\0') return s;
  if(s[2] == '\0') return s[0] == s[1] ? s : s + 1;

  int j = 1;
  int mb = 0;
  int me = 0;
  for(; s[j] != '\0'; j++) {
    if( s[j] == s[j - 1] || s[j] == s[j - 2]) {
      int k = 0;
      for(; s[j+k] == s[j-k-1] && s[j+k] != '\0' && s[j-k-1] >= 0; k++);
      k -= 1;
      if( 2*k + 2 > me - mb) {
        me = j + k;
        mb = j - k - 1;
      }
    }
    if( s[j] == s[j - 2]) {
      int k = 0;
      for(; s[j + k] == s[j - k - 2] && s[j+k] != '\0' && j-k-2 >= 0; k++);
      k -= 1;
      if( 2 * k + 3 > me - mb) {
        me = j + k;
        mb = j - k - 2;
      }
    }
  }
  s[me + 1] = '\0';
  return s + mb;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./longest_palindrome <string>\n");
    return 0;
  }

  char* pal = longestPalindrome(argv[1]);
  printf("%s\n", pal);
  return 0;
}
  

