#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 390. Elimination Game
 * There is a list of sorted integers from 1 to n.
 * Starting from left to right, remove the first number 
 * and every other number afterward until you reach the
 * end of the list.
 * Repeat the previous step again, but this time from right to left.
 * We keep repeating the steps again
 * until a single number remains.
 * Find the last number that remains starting with a list of length n.
 *
 * Example:
 * n = 9
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6 (6 is the answer)
 *
 * Runtime: 80ms;
 */
 
int lastRemaining(int n) {
  int ret = 1;
  int q = n;
  int p = 0;
  int f = 1;
  while(q != 1) {
    if(q % 2 == 1 || f) {
      ret += pow(2, p);
    }
    f = 1 - f;
    p += 1;
    q /= 2;
  }
  return ret;
}

int main(int argc, char** argv) {
  if(argc == 1) {
    printf("Usage: ./last_remain <number>\n");
    return 0;
  }

  int num = lastRemaining(atoi(argv[1]));
  printf("%d\n", num);
  return 0;
}
/*

1 2 3 4 5
  2   4
  2
------
n = 5
ret = 2 (idx == 1)
log2(5) = 2

 17 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
 8    2   4   6   8   10    12    14    16
 4    2       6       10          14
 2            6                   14
 1            6
-------
n = 17
ret = 6 (idx == 5)
log2(17) = 4

 26 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
 13   2   4   6   8   10    12    14    16    18    20    22    24    26
 6        4       8         12          16          20          24    
 3                8                     16                      24   
 1                                      16   
 -------
 n = 26
 ret = 16 (idx == 15)
 log2(26) = 4

*/