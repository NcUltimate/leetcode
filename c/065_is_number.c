#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

/*
 * 65. Valid Number
 * Validate if a given string is numeric. 
 * Some examples:
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
 *
 * Runtime:
 * [0-9]+ | [0-9]*\\.[0-9]+
 */

bool isNumber(char* s) {
  if(s[0] == '\0') return false;
  if(s[0] == 'e')  return false;
  const char* reg = "^ *([+-]?[0-9]+\\.?|[+-]?[0-9]*\\.[0-9]+)(e[+-]?[0-9]+)? *$";

  regex_t regex;
  regcomp(&regex, reg, REG_EXTENDED);
  return !regexec(&regex, s, 0, NULL, 0);
}

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Usage: ./is_number <str>\n");
    return 0;
  }

  bool match = isNumber(argv[1]);
  printf("%d\n", match);
  return 0;
}