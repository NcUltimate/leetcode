#include <stdio.h>
#include <stdlib.h>

/*
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the nth node from
 * the end of list and return its head.
 *
 * Runtime: 0ms
 */
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  if(head == NULL) return NULL;
  
  struct ListNode* last = NULL;
  struct ListNode* curr = head;
  int l = 0;
  while(curr != NULL) {
    l += 1;
    curr = curr->next;
  }
  if(n == l) return head->next;

  int idx = 0;
  curr = head;
  last = NULL;
  while(curr != NULL) {
    if(l - n != idx) {
      idx += 1;
      last = curr;
      curr = curr->next;
      continue;
    }
    if(last == NULL) return curr->next;
    last->next = curr->next;
    return head;
  }

  return head;
}

int main(int argc, char** argv) {
  if(argc < 3) {
    printf("Usage: ./remove_nth <n> <a1> <a2> ... <an>\n");
    return 0;
  }
  struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode) * (argc-2));
  struct ListNode* b = a;
  int idx = 2;
  while(idx + 1 < argc) {
    b->val = atoi(argv[idx]);
    b->next = b + 1;
    b = b->next;
    idx += 1;
  }
  b->val = atoi(argv[idx]);
  b->next = NULL;

  int n = atoi(argv[1]);
  struct ListNode* result = removeNthFromEnd(a, n);
  while(result != NULL) {
    printf("%d\n", result->val);
    result = result->next;
  }
  return 0;
}