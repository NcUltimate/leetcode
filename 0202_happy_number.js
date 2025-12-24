/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n) {
    let s = String(n)

    const seen = new Set();
    while (!seen.has(s)) {
        if (s === '1') {
            return true;
        }

        seen.add(s);

        let total = 0;
        for (let i = 0; i < s.length; i++) {
            const num = s.charCodeAt(i) - 48;
            total += num * num;
        }

        s = String(total);
    }
    return false;
};