#include <stdlib.h>
#include <stdio.h>

/*
 * 2. Add Two Numbers
 * You are given two linked lists representing two non-negative numbers. 
 *  The digits are stored in reverse order and each of their nodes
 *  contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * Runtime: 20ms
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* newNode(int val) {
  struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
  node-> val = val;
  node-> next = NULL;
  return node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if(l1 == NULL) return l2;
  if(l2 == NULL) return l1;

  struct ListNode* curr1 = l1;
  struct ListNode* curr2 = l2;
  struct ListNode* ret = NULL;
  struct ListNode* last = NULL;

  int sum = 0;
  while(curr1 != NULL || curr2 != NULL) {
    if( curr1 != NULL ) sum += curr1->val;
    if( curr2 != NULL ) sum += curr2->val;

    int digit = sum % 10;
    if( curr1 != NULL ) {
      curr1->val = digit;
      last = curr1;
      ret = l1;
      curr1 = curr1->next;
    }
    if( curr2 != NULL ) {
      curr2->val = digit;
      last = curr2;
      ret = l2;
      curr2 = curr2->next;
    }
    sum = sum / 10;
  }
  if ( sum ) {
    last->next = newNode(1);
  }
  return ret;
}

int main() {
  struct ListNode l1;
  struct ListNode l2;
  struct ListNode l3;
  l1.val = 5;
  l1.next = &l2;
  l2.val = 5;
  l2.next = &l3;
  l3.val = 5;
  l3.next = NULL;


  struct ListNode l4;
  struct ListNode l5;
  struct ListNode l6;
  l4.val = 5;
  l4.next = &l5;
  l5.val = 5;
  l5.next = &l6;
  l6.val = 5;
  l6.next = NULL;

  struct ListNode *result = addTwoNumbers(&l1, &l4);
  while(result != NULL) {
    printf("%d", result -> val);
    result = result ->next;
  }
  printf("\n");

  return 0;
}
