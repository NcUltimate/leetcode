#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

/*
 * 10. Regular Expression Matching
 * Implement regular expression matching 
 * with support for '.' and '*'.
 *
 * Runtime: 16ms
 */

bool isMatch(char* s, char* p) {
  int l = 0;
  for(; p[l] != '\0'; l++);

  int i = 0;
  char reg[l + 3];
  for(; i < l; i++) {
    reg[i + 1] = p[i];
  }
  reg[0] = '^';
  reg[l + 1] = '$';
  reg[l + 2] = '\0';

  regex_t regex;
  if(regcomp(&regex, reg, 0)) return false;
  return !regexec(&regex, s, 0, NULL, 0);
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./regex <str> <regex>\n");
    return 0;
  }

  bool match = isMatch(argv[1], argv[2]);
  printf("%d\n", match);
  return 0;
}