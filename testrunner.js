const fs = require('fs');
eval(fs.readFileSync('./0013_roman_to_int.js', 'utf8'));

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
    'MCDXLIV',
    'MMMIII',
    'IV',
    'IX',
    'XXXVI',
    'MDCCCLXXXVIII'
];

const solution = romanToInt;

testInputs.forEach((input, i) => {
    const result = solution(input);
    console.log(`Test ${i + 1}:`);
    console.log(`  Input: ${JSON.stringify(input)}`);
    console.log(`  Output: ${JSON.stringify(result)}\n`);
});
