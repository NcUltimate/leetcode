#include <stdlib.h>
#include <stdio.h>

/*
 * 1. Two Sum
 * Given an array of integers, return indices of the two 
 * numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * Runtime: 4ms
 */

int prime = 27499;

int hashKey(int num) {
  int key  = num % prime;
  return key < 0 ? key + prime : key;
}

int* twoSum(int* nums, int numsSize, int target) {
  int* result = (int*)malloc(sizeof(int) * 2);
  result[0] = -1;
  result[1] = -1;

  int hash[prime];
  int j = 0;
  for(; j < numsSize; j++){
    int key1  = hashKey(nums[j]);
    int key2  = hashKey(target - nums[j]);
    hash[key1] = -1;
    hash[key2] = -1;
  }

  // main algorithm
  int idx = 0;
  int dub = -1;
  for(; idx < numsSize; idx++) {
    int n = nums[idx];

    // for duplicates
    if( target % 2 == 0 && n == target / 2) {
      if(dub == -1) {
        dub = idx;
        continue;
      }
      else {
        result[0] = dub;
        result[1] = idx;
        break;
      }
    }

    int key  = hashKey(target - n);
    if( hash[key] != -1 ){
      result[0] = hash[key] < idx ? hash[key] : idx;
      result[1] = hash[key] > idx ? hash[key] : idx;
      break;
    }

    int nkey = hashKey(n);
    hash[nkey] = idx;
  }

  return result;
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./two_sum <target> <item1> (item2 item3 ... itemn)?\n");
    return 0;
  }

  int numsSize = argc - 2;
  int target = atoi(argv[1]);

  int idx = 2;
  int nums[numsSize];
  for(; idx < argc; idx++) {
    nums[idx - 2] = atoi(argv[idx]);
  }

  int* result = twoSum(nums, numsSize, target);
  printf("[%d, %d]\n", result[0], result[1]);

  return 0;
}