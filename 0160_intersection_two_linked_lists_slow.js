/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let seenA = new Set();

    let currA = headA;
    while (currA !== null) {
        seenA.add(currA);
        currA = currA.next;
    }

    let currB = headB;
    while (currB !== null) {
        if (seenA.has(currB)) {
            return currB;
        }
        currB = currB.next;
    }

    return null;
};