/**
 * Return every possible nesting of parenthesis for n.
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];
    
    function generateParenthesisR(current, openCount, closeCount) {
        if (current.length === 2 * n) {
            result.push(current);
            return;
        }
        
        if (openCount < n) {
            generateParenthesisR(current + '(', openCount + 1, closeCount);
        }
        
        if (closeCount < openCount) {
            generateParenthesisR(current + ')', openCount, closeCount + 1);
        }
    }
    
    generateParenthesisR('', 0, 0);
    return result;
};