const fs = require('fs');
eval(fs.readFileSync('./0125_valid_palindrome_pointers.js', 'utf8'));

const testInputs = [
    "A man, a plan, a canal: Panama",
    "race a car",
    "racecar",
    "ap",
    "0P",
    " ",
    "   ",
];

const solution = isPalindrome;

testInputs.forEach((input, i) => {
    const result = solution(...(Array.isArray(input) ? input : [input]));
    console.log(`Test ${i + 1}:`);
    console.log(`  Input: ${JSON.stringify(input)}`);
    console.log(`  Output: ${JSON.stringify(result)}\n`);
});
