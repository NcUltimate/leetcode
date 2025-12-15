
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    if (intervals.length === 0) {
        return [newInterval];
    }

    if (intervals[0][0] > newInterval[1]) {
        intervals.unshift(newInterval);
        return intervals;
    }

    if (intervals[intervals.length - 1][1] < newInterval[0]) {
        intervals.push(newInterval);
        return intervals;
    }
    
    let idx = 0;
    let didPushInterval = false;
    const result = [];
    while (idx < intervals.length) {   
        const current = intervals[idx];
        if (current[1] < newInterval[0]) {
            result.push(current);
            idx ++;
            continue;
        }
        else if (current[0] > newInterval[1]) {
            if (!didPushInterval) {
                result.push(newInterval);
                didPushInterval = true;
            }
            result.push(current);
            idx ++;
            continue;
        }
        else {
            newInterval[0] = Math.min(newInterval[0], current[0]);
            newInterval[1] = Math.max(newInterval[1], current[1]);
        }
        idx ++;
    }

    if (!didPushInterval) {
        result.push(newInterval);
    }

    return result;
};