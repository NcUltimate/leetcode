#include <stdlib.h>
#include <stdio.h>

/*
 * 21. Merge two sorted lists
 * Merge two sorted linked lists and return it as a new list. 
 *
 * The new list should be made by splicing together 
 * the nodes of the first two lists.
 *
 * Runtime: 4ms
 */
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  if(l1 == NULL) return l2;
  if(l2 == NULL) return l1;

  struct ListNode* ret = NULL;
  struct ListNode* curr = NULL;
  while(l1 || l2) {
    if(l1 == NULL) {
      curr->next = l2;
      break;
    }
    if(l2 == NULL) {
      curr->next = l1;
      break;
    }

    if(l1->val <= l2->val) {
      if(ret == NULL){
        curr = l1;
        ret = curr;
      }
      else {
        curr->next = l1;
        curr = curr->next;
      }

      l1 = l1->next;
    }
    else {
      if(ret == NULL){
        curr = l2;
        ret = curr;
      }
      else {
        curr->next = l2;
        curr = curr->next;
      }

      l2 = l2->next;
    }
  }
  return ret;
}

struct ListNode* buildList(char** argv, int start, int end) {
  if(start >= end) return NULL;

  struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode) * (end - start));
  struct ListNode* b = a;
  int idx = start;
  while(idx + 1 < end) {
    b->val = atoi(argv[idx]);
    b->next = b + 1;
    b = b->next;
    idx += 1;
  }
  b->val = atoi(argv[idx]);
  b->next = NULL;
  return a;
}

int main(int argc, char** argv) {
  if( argc < 2 ) {
    printf("Usage: ./merge a1 ... an %% b1 ... bn\n");
    return 0;
  }

  int i=0;
  int mod = 0;
  for(; i < argc; i++) {
    if( argv[i][0] == '%' ) mod = i;
  }

  if( !mod ) {
    printf("Error: %% must be specified between lists.\n");
    printf("Usage: ./merge a1 ... an %% b1 ... bn\n");
    return 0;
  }

  struct ListNode* a = buildList(argv, 1, mod);
  struct ListNode* b = buildList(argv, mod + 1, argc);

  struct ListNode* result = mergeTwoLists(a, b);
  while(result != NULL) {
    printf("%d ", result->val);
    result = result->next;
  }
  printf("\n");
  return 0;
}
  

