/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * Get the length of a linked list
 * @param {ListNode} node 
 * @returns {number} The length of the linked list
 */
function getLength(node) {
    let len = 0;
    while (node) {
        len++;
        node = node.next;
    }
    return len;
}

/**
 * Find the intersection of two linked lists
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let lenA = getLength(headA);
    let lenB = getLength(headB);

    let ptrA = headA;
    let ptrB = headB;

    // Advance the longer list's pointer by difference in lengths
    if (lenA > lenB) {
        for (let i = 0; i < lenA - lenB; i++) {
            ptrA = ptrA.next;
        }
    } else if (lenB > lenA) {
        for (let i = 0; i < lenB - lenA; i++) {
            ptrB = ptrB.next;
        }
    }

    while (ptrA && ptrB) {
        if (ptrA === ptrB) return ptrA;
        ptrA = ptrA.next;
        ptrB = ptrB.next;
    }

    return null;
};
