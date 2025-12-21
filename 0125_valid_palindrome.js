/**
 * Checks whether ONLY the alphanumeric characters in s represent a palindrome
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
    for (let i=0; i < s.length / 2; i++) {
        if (s.charAt(i) !== s.charAt(s.length - i - 1)) {
            return false;
        }
    }
    return true;
};