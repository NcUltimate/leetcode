#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * 6. ZigZag Conversion 
 * The string "PAYPALISHIRING" is written in a zigzag pattern  
 * on a given number of rows like this: 
   P   A   H   N
   A P L S I I G
   Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion 
 * given a number of rows.
 *
 * Runtime: 4ms
 */

char* convert(char* s, int numRows) {
  if(numRows == 0) return "";
  if(numRows == 1) return s;

  int i = 0;
  int l = 0;
  for(; s[l] != '\0'; l++);
  if(numRows >= l) return s;

  int row = 0;
  int dcol = ( 2*numRows - 2 );
  int zidx = 0;
  char* zigzag = (char*) malloc(sizeof(char) * (l+1));
  while( row != numRows ) {
    int idx = row;
    int d[2];
    d[0] = dcol - row*2;
    d[1] = row*2;

    int didx = 0;
    while( idx < l ) {
      if(d[didx] == 0) didx = 1 - didx;
      zigzag[zidx] = s[idx];
      idx += d[didx];
      didx = 1 - didx;
      zidx += 1;
    }
    row += 1;
  }
  zigzag[l] = '\0';
  return zigzag;
}

int main(int argc, char** argv) {
  if( argc < 3 ) {
    printf("Usage: ./zig_zag <string> <numrows>\n");
    return 0;
  }

  char* zigzag = convert(argv[1], atoi(argv[2]));
  printf("%s\n", zigzag);
  return 0;
}