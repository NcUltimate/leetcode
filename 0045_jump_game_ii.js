/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function (nums) {
    // Case 1: Trivial array length
    if (nums.length <= 1) {
        return 0;
    }

    let minJumps = 0;
    let currentEnd = 0;
    let farthest = 0;

    for (let i = 0; i < nums.length - 1; i++) {
        farthest = Math.max(farthest, i + nums[i]);

        if (i === currentEnd) {
            minJumps++;
            currentEnd = farthest;
        }
    }

    return minJumps;
};