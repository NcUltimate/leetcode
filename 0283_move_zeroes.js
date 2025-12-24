/**
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    // We can solve this with two "pointers".
    let zero = 0;
    let nonzero = 0;
    while (zero < nums.length && nonzero < nums.length) {
        if (nums[nonzero] === 0) {
            nonzero ++;
        }
        else if (nums[zero] !== 0) {
            zero ++;
            if (zero > nonzero) {
                nonzero = zero;
            }
        }
        else if (nums[nonzero] !== 0 && nums[zero] === 0) {
            nums[zero] = nums[nonzero];
            nums[nonzero] = 0;
        }
    }
    return nums;
};