#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contains(int* rect, double x, double y) {
  if (y < rect[1] || y > rect[3]) return false;
  if (x < rect[0] || x > rect[2]) return false;
  return true;
}
bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize) {
  if(rectanglesRowSize == 1) return 1;

  printf("Setting min/max...\n");
  int x_min = rectangles[0][0];
  int y_min = rectangles[0][1];
  int x_max = rectangles[0][2];
  int y_max = rectangles[0][3];

  printf("Running...\n");
  int i=0;
  for(; i < rectanglesRowSize; i++) {
    int j=0;
    for(; j< rectanglesColSize; j++) {
      if(j%2==1) {
        if(rectangles[i][j] > y_max) y_max = rectangles[i][j];
        if(rectangles[i][j] < y_min) y_min = rectangles[i][j];
      }
      else {
        if(rectangles[i][j] > x_max) x_max = rectangles[i][j];
        if(rectangles[i][j] < x_min) x_min = rectangles[i][j];
      }
    }
  }
  printf("x_min=%d y_min=%d x_max=%d y_max=%d\n", x_min, y_min, x_max, y_max);

  int none = true;
  bool marked[x_max - x_min][y_max - y_min];

  int need_marked = (y_max - y_min) * (x_max - x_min);
  printf("%d to be marked.\n", need_marked);
  int i2 = 0;
  for(i2=0; i2 < x_max - x_min; i2++) {
    int i3 = 0;
    for(; i3 < y_max - y_min; i3++) {
      printf("Setting (%d, %d) to false.\n", i2, i3);
      marked[i2][i3] = false;
    }
  }
  printf("Running algorithm...\n");

  // For each rectangle
  for(i=0; i < rectanglesRowSize; i++) {
    int *rect = rectangles[i];
    printf("Looking at [%d, %d, %d, %d]\n", rect[0], rect[1], rect[2], rect[3]);
    int j = rect[0];
    for(; j <= rect[2] - 1; j++) {

      int k = rect[1];
      for(; k <= rect[3] - 1; k++) {

        printf("marking (%d, %d) == (%d, %d)\n", j, k, j - x_min, k - y_min);
        if(marked[j - x_min][k - y_min]) return false;

        marked[j - x_min][k - y_min] = true;
        need_marked -= 1;
      }
    }
  }
  printf("%d left to be marked.\n", need_marked);
  if(need_marked) return false;
  return true;
}
/*
  double j = x_min + 0.5;
  for(; j < x_max; j+=1) {
    double k = y_min + 0.5;
    for(; k < y_max; k+=1) {
      printf("%f %f\n", j, k);
      int none = true;
      for(i=0; i<rectanglesRowSize; i++) {
        if( contains(rectangles[i], j, k) ) {
          none = false;
          break;
        }
      }
      if(none) return false;
    }
  }
  return true;
  */

int main(int argc, char** argv) {
  int* x[4];
  int i = 0;
  x[0] = (int*) malloc(sizeof(int)*4);
  x[0][0] = 1;
  x[0][1] = 1;
  x[0][2] = 2;
  x[0][3] = 3;

  x[1] = (int*) malloc(sizeof(int)*4);
  x[1][0] = 1;
  x[1][1] = 3;
  x[1][2] = 2;
  x[1][3] = 4;

  x[2] = (int*) malloc(sizeof(int)*4);
  x[2][0] = 3;
  x[2][1] = 1;
  x[2][2] = 4;
  x[2][3] = 2;

  x[3] = (int*) malloc(sizeof(int)*4);
  x[3][0] = 3;
  x[3][1] = 2;
  x[3][2] = 4;
  x[3][3] = 4;

  printf("executing...\n");
  int cover = isRectangleCover(x, 4, 4);
  printf("%d\n", cover);
  return 0;
}