/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    // Case 1: if the item at 0 is 0, we can't move
    if (nums.length === 0) {
        return false;
    }

    // Case 2: The array is length 1 - we can always hit the end
    if (nums.length === 1) {
        return true;
    }

    // Case 3: Otherwise handle nontrivial cases
    let curNum = nums[0];
    let index = 1;

    while (curNum != 0 && index < nums.length - 1) {
        curNum --;
        if (nums[index] > curNum) {
            curNum = nums[index];
        }
        index ++;
    }

    return curNum > 0;
};