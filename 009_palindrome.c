#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 9. Palindrome Number
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 *
 * Runtime: 48ms
 */

int palindrome(int num) {
  if(num < 0) { return 0; }
  if(num < 10) { return 1; }

  int n = log10(num);
  int l = n + 1;
  int c = n;
  while(c >= l / 2) {
    int d = l - c - 1;
    int p1 = pow(10, c);
    int p2 = pow(10, d);

    int y = ((num - (num % p1)) / p1) % 10;
    int z = ((num - (num % p2)) / p2) % 10;
    if(y != z) {
      return 0;
    }
    c = c - 1;
  }
  return 1;
}

int main(int argc, char** argv) {
  if(argc == 1) {
    printf("Usage: ./palindrome <number>\n");
    return 0;
  }

  int number = atoi(argv[1]);
  if(palindrome(number)) {
    printf("%d is a palindrome.\n", number);
  }
  else {
    printf("%d is not a palindrome.\n", number);
  }
  return 0;
}