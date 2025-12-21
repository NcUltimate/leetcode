/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if (height.length < 2) {
        return 0;
    }
    
    // Use two pointers to compute the max area
    let leftPtr = 0
    let rightPtr = height.length - 1;

    let maxArea = -1;
    while (leftPtr != rightPtr) {
        const side1 = Math.min(height[leftPtr], height[rightPtr]);
        const side2 = rightPtr - leftPtr;
        const area = side1 * side2;
        if (area > maxArea) {
            maxArea = area;
        }

        if (height[leftPtr] < height[rightPtr]) {
            leftPtr ++;
        }
        else {
            rightPtr --;
        }
    }

    return maxArea;
};