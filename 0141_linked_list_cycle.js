/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * Given a linked list, determine if it has a cycle in it.
 * It's a classic two-pointer problem, one slow and one fast.
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let ptr1 = head;
    let ptr2 = head;
    while (ptr1 !== null && ptr2 !== null) {
        ptr1 = ptr1?.next;
        ptr2 = ptr2?.next;
        ptr2 = ptr2?.next;

        if (ptr1 === ptr2 && ptr1 !== null) {
            return true;
        }
    }

    return false;
};