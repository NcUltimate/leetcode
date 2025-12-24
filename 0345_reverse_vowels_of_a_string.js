const VREG = /[aeiou]/i;
function matches(v1, v2) {
    const v1c = v1.charCodeAt(0);
    const v2c = v2.charCodeAt(0);
    return v1c === v2c || Math.abs(v2c - v1c) === 35;
}

/**
 * Given a string s, reverse only the vowels of the string.
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    const arr = s.split('');
    let left = 0;
    let right = s.length - 1;
    while (left < right) {
        if (!VREG.test(arr[left])) {
            left ++;
        }
        else {  
            if (!VREG.test(arr[right])) {
                right --;
            }
            else {
                const temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left ++;
                right --;
            }
        }
    }

    return arr.join('');
};