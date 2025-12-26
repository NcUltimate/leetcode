function expandAroundCenter(s, left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

/**
 * Find the longest palindrome within the string
    "babadook, dook, dook!", // bab
    "bubbling with fizziness", // izzi
    "a bee eats a banana", // anana
    "A very popular racecar track", // racecar
    "yabbadabbadoo!" //abbadabba
 * @param {string} s the input string
 * @return {string} the longest palindrome
 */
var longestPalindrome = function(s) {
    if (s.length <= 1) {
        return s;
    }

    let start = 0;
    let maxLength = 1;
    
    for (let i = 0; i < s.length; i++) {
        let oddLength = expandAroundCenter(s, i, i);
        let evenLength = expandAroundCenter(s, i, i + 1);
        let currentLength = Math.max(oddLength, evenLength);
        
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = i - Math.floor((currentLength - 1) / 2);
        }
    }
    
    return s.substring(start, start + maxLength);
};