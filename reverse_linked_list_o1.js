/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * Reverse a singly linked list.
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseSinglyLinkedList = function(head) {
    // Handle trivial & degenerate cases
    if (head === null) {
        return null;
    }

    if (head.next === null) {
        return head;
    }

    // Handle main cases
    let prev = null;
    let curr = head;
    while (curr != null) {
        let next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
};