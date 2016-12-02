#include <stdio.h>
#include <stdbool.h>

/*
 * 20. Valid Parenthesis
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}"
 * are all valid but "(]" and "([)]" are not.
 *
 * Runtime: 0ms
 */

bool isValid(char* s) {
  if(s[0] == '\0') return true;
  if(s[1] == '\0') return false;

  int l = 0;
  for(; s[l] != '\0'; l++);
  if(l % 2 == 1) return false;

  int sl = 0;
  char stack[l];

  int idx = 0;
  for(; s[idx] != '\0'; idx++) {
    if(s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
      stack[sl++] = s[idx];
      continue;
    }
    sl--;
    if(s[idx] == ')' && stack[sl] != '(') return false;
    if(s[idx] == '}' && stack[sl] != '{') return false;
    if(s[idx] == ']' && stack[sl] != '[') return false;
  }
  return sl == 0 ? true : false;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./parenthesis <string>\n");
    return 0;
  }

  bool valid = isValid(argv[1]);
  printf("%d\n", valid);
  return 0;
}