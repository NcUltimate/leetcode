#include <stdlib.h>
#include <stdio.h>

/*
 * 3. Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Example: Given "abcabcbb", the answer is "abc", which the length is 3.
 * Example: Given "pwwkew", the answer is "wke", with the length of 3.
 *
 * Runtime: 4ms
 */

int max(a, b) {
  return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
  if( s[0] == '\0' ) return 0;
  if( s[1] == '\0' ) return 1;
  int ret = 0;
  int b  = 0;
  int e  = 0;

  int seen[128];
  int i = 0;
  for(; i < 128; i++) {
    seen[i] = -1;
  }

  for(; s[e] != '\0'; e++) {
    int ch = (int) s[e];
    if( seen[ch] != -1 ) {
      if( e - b >= ret ) ret = e - b;
      b = max(b, seen[ch] + 1);
    }
    seen[ch] = e;
  }

  return max(e - b, ret);
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./longest_norepeat_substr <string>\n");
    return 0;
  }

  int length = lengthOfLongestSubstring(argv[1]);
  printf("%d\n", length);
  return 0;
}
  

