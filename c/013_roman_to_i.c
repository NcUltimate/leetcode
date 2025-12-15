#include <stdio.h>

/*
 * 13. Roman to Integer
 * Given a roman numeral, convert it to an integer.
 *
 * Runtime: 16ms
 */

int rtoi(char r) {
  switch(r) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return 0;
  }
}

int romanToInt(char* s) {
  int l = 0;  
  for(; s[l] != '\0'; l++);
  
  int p = 0;
  int sum = 0;
  int i = l - 1;
  for(; i > -1; i--){
    int r = rtoi(s[i]);
    if(p == 0 || r >= p) {
      sum += r;
    }
    else {
      sum -= r;
    }
    p = r;
  }
  return sum;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./rtoi <string>\n");
    return 0;
  }

  int num = romanToInt(argv[1]);
  printf("%d\n", num);
  return 0;
}