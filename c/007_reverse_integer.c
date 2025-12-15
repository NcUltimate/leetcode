#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
 * 7. Reverse Integer
 * Reverse the digits of an integer.
 *
 * Runtime: 4ms
 */

int reverse(int x) {
  if(x < 10 && x > - 10) return x;

  int y = abs(x);
  int p = log10(y);
  int sum = 0;
  while(y > 0) {
    int digit = y % 10;
    if(digit > 2 && p > 8) return 0;

    sum += (digit * pow(10, p));

    y /= 10;
    p -= 1;
  }
  if(sum < 0) return 0;
  return x < 0 ? -sum : sum;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./reversi <number>\n");
    return 0;
  }

  int rev = reverse(atoi(argv[1]));
  printf("%d\n", rev);
  return 0;
}