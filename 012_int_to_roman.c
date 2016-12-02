#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * 12. Integer to Roman (atoi)
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within
 * the range from 1 to 3999.
 *
 * Runtime: 9ms, 15ms, 12ms, 19ms
 */

char itor(int num) {
  switch(num) {
    case 1000: return 'M';
    case 500: return 'D';
    case 100: return 'C';
    case 50: return 'L';
    case 10: return 'X';
    case 5: return 'V';
    case 1: return 'I';
    default: return ' ';
  }
}

int tens[5] = { 1000, 1000, 100, 10, 1};
int ones[5] = { 1000, 100, 10, 1, 1};

char* intToRoman(int num) {
  int rem = num;
  int idx = 0;
  int sidx = 0;

  // Maximum length of Roman <= 3999 is 3888
  // (MMMDCCCLXXXVIII) with 16 chars.
  char* str = (char*) malloc(sizeof(char) * 16);
  while(idx < 5) {
    int q = rem / ones[idx];
    if(q == 9) {
      str[sidx++] = itor(ones[idx]);
      str[sidx++] = itor(tens[idx]);
      rem = rem - (q * ones[idx]);
      idx += 1;
    }
    else if(q >= 5) {
      str[sidx++] = itor(5 * ones[idx]);
      rem = rem - (5 * ones[idx]);
    }
    else if(q == 4) {
      str[sidx++] = itor(ones[idx]);
      str[sidx++] = itor(5*ones[idx]);
      rem = rem - (q * ones[idx]);
      idx += 1;
    }
    else {
      char c = itor(ones[idx]);
      int i = 0;
      for(; i < q; i++) {
        str[sidx++] = c;
      }
      rem = rem - (q * ones[idx]);
      idx += 1;
    }
  }
  str[sidx] = '\0';
  return str; 
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./itor <number>\n");
    return 0;
  }
  int num = atoi(argv[1]);
  if(num <= 0 || num > 3999) {
    printf("Error: number out of range.\n");
    return 0;
  }

  char* result = intToRoman(num);
  printf("%s\n", result);
  return 0;
}