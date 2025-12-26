const fs = require('fs');
eval(fs.readFileSync('./0002_add_two_numbers.js', 'utf8'));

const ListNode = (val) => ({ val, next: null });

const createLinkedList = (arr) => {
    let head = ListNode(arr[0]);
    let current = head;
    for (let i = 1; i < arr.length; i++) {
        current.next = ListNode(arr[i]);
        current = current.next;
    }
    return head;
}

const testInputs = [
    [createLinkedList([2, 4, 3]), createLinkedList([5, 6, 4])],
    [createLinkedList([0]), createLinkedList([0])],
    [createLinkedList([9, 9, 9, 9, 9, 9, 9]), createLinkedList([9, 9, 9, 9])],
];

const solution = addTwoNumbers;

testInputs.forEach((input, i) => {
    const result = solution(input);
    console.log(`Test ${i + 1}:`);
    console.log(`  Input: ${JSON.stringify(input)}`);
    console.log(`  Output: ${JSON.stringify(result)}\n`);
});
