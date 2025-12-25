/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    // Handle trivial and degenerate cases first
    if (strs.length === 0) {
        return "";
    }

    if (strs.length === 1) {
        return strs[0];
    }

    // Handle all other cases
    let maxIdx = 0;
    while (maxIdx < strs[0].length) {
        let done = false;
        let currChar = strs[0].charAt(maxIdx);
        for (let strIdx = 1; strIdx < strs.length; strIdx ++) {
            if (strs[strIdx].charAt(maxIdx) !== currChar) {
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
        maxIdx ++;
    }

    if (maxIdx === -1) {
        return "";
    }

    return strs[0].slice(0, maxIdx);
};