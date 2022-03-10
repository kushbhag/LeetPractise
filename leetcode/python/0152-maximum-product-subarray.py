# https://leetcode.com/problems/maximum-product-subarray/
# Medium

# Keep track of max and min product so far
# Continously multiply by `n` at each point
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currMax = currMin = 1
        maxSoFar = nums[0]

        for n in nums:
            currMax, currMin = max(currMax*n, currMin*n, n), min(currMax*n, currMin*n, n)
            maxSoFar = max(currMax, maxSoFar)
        return maxSoFar
