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

/**
 * Given a singly linked list, determine if it is a palindrome.
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    // Degenerate and trivial cases
    if (head === null || head.next === null) {
        return true;
    }

    // 1. Find the middle / length of the linkedlist
    let slow = head;
    let fast = head;
    while (fast !== null) {
        slow = slow?.next || null;
        fast = fast?.next?.next || null;
    }

    // 2. reverse the 2nd "half" of the linkedlist
    let right = reverseSinglyLinkedList(slow);

    // 3. traverse 1st & 2nd halves to detect any mismatches
    let left = head;
    while (left !== null && right !== null) {
        if (left.val !== right.val) {
            return false;
        }

        left = left?.next;
        right = right?.next;
    }


    return true; 
};