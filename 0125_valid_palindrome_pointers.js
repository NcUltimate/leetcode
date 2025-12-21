/**
 * Checks whether ONLY the alphanumeric characters in s represent a palindrome.
 * Does this WITHOUT using toLowerCase or replace
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let lIdx = 0;
    let rIdx = s.length - 1;
    while (lIdx < rIdx) {
        // Find the next alphanumeric character on the left
        let l = s.charCodeAt(lIdx);
        while (lIdx < s.length && !((l >= 48 && l <= 57) || (l >= 65 && l <= 90) || (l >= 97 && l <= 122))) {
            lIdx ++;
            l = s.charCodeAt(lIdx);
        }

        // Find the next alphanumeric character on the right
        let r = s.charCodeAt(rIdx);
        while (rIdx > -1 && !((r >= 48 && r <= 57) || (r >= 65 && r <= 90) || (r >= 97 && r <= 122))) {
            rIdx --;
            r = s.charCodeAt(rIdx);
        }

        if (lIdx > rIdx) {
            return true;
        }

        if (!(l === r || (l > 57 && r > 57 && Math.abs(l - r) === 32))) {
            return false;
        }

        lIdx ++;
        rIdx --;
    }

    return true;
};