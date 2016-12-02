#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

/*
 * 11. Container With Most Water
 * Given n non-negative integers (a1, a2, ..., an)
 * where each represents a point at coordinate (i, ai)
 * Find two lines, which together with x-axis forms a container
 * such that the container has the largest area.
 *
 * Runtime:
 */

int maxArea(int* height, int heightSize) {
  int i = 0;
  int max = 0;
  for(; i < heightSize - 1; i++) {

    int j = i + 1;
    for(; j < heightSize; j++) {
      int h = height[j] < height[i] ? height[j] : height[i];
      int w = j - i;
      int area = w * h;
      if(area > max) max = area;
    }
  }
  return max;
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./area <a1> <a2> ... <an>\n");
    return 0;
  }
  int nums[argc - 1];
  int i = 1;
  for(; i < argc; i++) {
    nums[i - 1] = atoi(argv[i]);
  }

  int area = maxArea(nums, argc - 1);
  printf("%d\n", area);
  return 0;
}