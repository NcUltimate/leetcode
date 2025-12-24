/**
 * Convert a roman numeral, e.g. MCDXLIV, to an int, e.g. 1444
 * Example inputs:
 *   'MCDXLIV'
 *   'MMMIII'
 *   'IV'
 *   'IX'
 *   'XXXVI'
 *   'MDCCCLXXXVIII'
 * @param {string} s - The roman numeral to convert to an integer
 * @return {number} - The integer value of the roman numeral
 */
var romanToInt = function(s) {
    let total = 0;
    let subTotal = 0;
    let prevValue = undefined;
    for (let pos = 0; pos < s.length; pos++) {
        let value = 0;
        const char = s.charAt(pos);
        if (char === 'M') {
            value = 1000;
        }
        else if(char === 'D') {
            value = 500;
        }
        else if(char === 'C') {
            value = 100;
        }
        else if(char === 'L') {
            value = 50;
        }
        else if(char === 'X') {
            value = 10;
        }
        else if(char === 'V') {
            value = 5;
        }
        else if(char == 'I') {
            value = 1;
        }

        if (prevValue && value > prevValue) {
            subTotal = Math.abs(value - subTotal);
        }
        else if (!prevValue || value === prevValue) {
            subTotal += value;
        }
        else {
            total += subTotal;
            subTotal = value;
        }

        prevValue = value;
    }

    total += subTotal;

    return total;
};