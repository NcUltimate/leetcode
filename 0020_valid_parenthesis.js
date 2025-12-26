/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const stack = [];
    let idx = 0;
    for (; idx < s.length; idx++) {
        if (s.charAt(idx) === '(') {
            stack.push('(');
            continue;
        }
        else if (s.charAt(idx) === '[') {
            stack.push('[');
            continue;
        }
        else if (s.charAt(idx) === '{') {
            stack.push('{');
            continue;
        }

        if (s.charAt(idx) === ')') {
            if (stack[stack.length - 1] === '(') {
                stack.pop();
            }
            else {
                return false;
            }
        }
        else if (s.charAt(idx) === '}') {
            if (stack[stack.length - 1] === '{') {
                stack.pop();
            }
            else {
                return false;
            }
        }
        else if (s.charAt(idx) === ']') {
            if (stack[stack.length - 1] === '[') {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }
    return stack.length === 0;
};

var isValidParenthesis = isValid;