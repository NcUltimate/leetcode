#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * 8. String to Integer (atoi)
 * Implement atoi to convert a string to an integer.
 *
 * Runtime: 4ms
 */

int isDigit(char c) {
  return (c >= '0' && c <= '9') || c == ' ' || c == '-' || c == '+';
}

int myAtoi(char* str) {
  if(str[0] == '\0') return 0;
  int i = 0;
  while(str[i] != '\0') {
    if(!isDigit(str[i])) {
      str[i] = '\0';
      break;
    }
    i += 1;
  }
  double d = atof(str);
  if(d >= 2147483647.0) return 2147483647;
  if(d <= -2147483648.0) return -2147483648;

  return d;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./myatoi <number>\n");
    return 0;
  }

  int result = myAtoi(argv[1]);
  printf("%d\n", result);
  return 0;
}