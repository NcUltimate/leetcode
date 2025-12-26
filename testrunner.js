const fs = require('fs');
eval(fs.readFileSync('./0022_generate_parenthesis.js', 'utf8'));

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
    1,
    3,
    5
];

const solution = generateParenthesis;

testInputs.forEach((input, i) => {
    const result = solution(input);
    console.log(`Test ${i + 1}:`);
    console.log(`  Input: ${JSON.stringify(input)}`);
    console.log(`  Output: ${JSON.stringify(result)}\n`);
});
