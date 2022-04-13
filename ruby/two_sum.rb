# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
require 'set'

def two_sum(nums, target)
  hash  = {}
  idx1  = -1
  k     = 0
  half  = target / 2
  while(k < nums.length)
    n = nums[k]

    if n == half
      if idx1 == -1
        idx1 = k
        next k += 1
      else
        return [idx1, k]
      end
    end

    diff  = target - n
    hdiff = hash[diff]
    if hdiff
      min = hdiff < k ? hdiff : k
      max = hdiff > k ? hdiff : k
      
      return [min, max]
    end

    hash[n] = k
    k += 1
  end
end