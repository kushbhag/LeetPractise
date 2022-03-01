# https://leetcode.com/problems/maximum-subarray/
# Easy

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSoFar, currSum = nums[0], 0

        for n in nums:
            currSum = max(n, currSum + n)
            maxSoFar = max(maxSoFar, currSum)
                
        return maxSoFar
            