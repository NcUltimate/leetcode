#include <stdlib.h>
#include <stdio.h>

/*
 * 15. Three Sum
 * Given an array of integers, return indices of the three 
 * numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * Runtime: 79ms
 */

int prime = 27499;

int hashKey(int num) {
  int key  = num % prime;
  return key < 0 ? key + prime : key;
}
int bigKey(int a, int b, int c) {
  int num = a*229 + b*11 + c*863;
  return hashKey(num);
}
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return -1;
    if (f < s) return  1;
    return 0;
}
int* buildResult(int a, int b, int c) {
  int* ret = (int*) malloc(sizeof(int) * 3);
  ret[0] = a;
  ret[1] = b;
  ret[2] = c;
  return ret;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), comp);
  int** ret = (int**) malloc(sizeof(int*) * 10000);
  int seen[prime];
  int j = 0;
  for(; j < prime; j++){
    seen[j] = -1;
  }

  int i1 = 0;
  for(; i1 < numsSize; i1++) {
    int target = -nums[i1];

    int hash[prime];
    for(j = 0; j < numsSize; j++){
      int key1  = hashKey(nums[j]);
      int key2  = hashKey(target - nums[j]);
      hash[key1] = -1;
      hash[key2] = -1;
    }

    // main algorithm
    int i2 = i1 + 1;
    int dub = -1;
    for(; i2 < numsSize; i2++) {
      int n = nums[i2];
      int* res = NULL;

      // for duplicates
      if( target % 2 == 0 && n == target / 2) {
        if(dub == -1) {
          dub = i2;
          continue;
        }
        else if(dub != -2) {
          res = buildResult(nums[dub], nums[i2], nums[i1]);
          dub = -2;
        }
      }

      int key  = hashKey(target - n);
      if( hash[key] != -1){
        res = buildResult(nums[hash[key]], nums[i2], nums[i1]);
      }

      int nkey = hashKey(n);
      hash[nkey] = i2;
      if(res != NULL) {
        int bkey = bigKey(res[0], res[1], res[2]);
        if(seen[bkey] == -1) {
          ret[*returnSize] = res;
          *returnSize+=1;
          seen[bkey] = 1;
        }
      }
    }
  }
  return ret;
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./3sum <item1> (item2 item3 ... itemn)?\n");
    return 0;
  }

  int numsSize = argc - 1;

  int idx = 1;
  int nums[numsSize];
  for(; idx < argc; idx++) {
    nums[idx - 1] = atoi(argv[idx]);
  }

  int retSize = 0;
  int** result = threeSum(nums, numsSize, &retSize);
  int i = 0;
  for(; i < retSize; i++) {
    int* ret = result[i];
    printf("[%d, %d, %d]\n", ret[0], ret[1], ret[2]);
  }

  return 0;
}