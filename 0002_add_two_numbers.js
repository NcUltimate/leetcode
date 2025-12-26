/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * Sum two linked lists, returning the result in one of the
 * existing linked lists for O(1) memory usage. Keep track of
 * which list is longest using currHead.
 * 
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */var addTwoNumbers = function(l1, l2) {
    // handle trivial and degenerate cases
    if (l1 === null) {
        return l2;
    }

    if (l2 === null) {
        return l1;
    }

    let currl1 = l1;
    let currl2 = l2;
    let currHead = l1;
    let prev = null;
    let carry = 0;
    while (currl1 !== null || currl2 !== null) {
        const temp = (currl1?.val || 0) + (currl2?.val || 0) + carry;
        if (currl1) {
            currl1.val = temp % 10;
            prev = currl1;
            currHead = l1;
        }
        
        if (currl2) {
            currl2.val = temp % 10;
            prev = currl2;
            currHead = l2;
        }

        carry = Math.floor(temp / 10);
        currl1 = currl1?.next || null;
        currl2 = currl2?.next || null;
    }

    if (carry) {
        prev.next = { val: carry, next: null };
    }

    return currHead;
};
