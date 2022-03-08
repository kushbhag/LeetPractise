# https://leetcode.com/problems/longest-consecutive-sequence/
# Medium

# Create set containing all the elements
# For all n in nums, go through all n,n+1,n+2,...,n+k if n-1 does not exist in set
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        maxLen = 0
        for n in nums:
            if n-1 not in s:
                l = n
                while l in s:
                    l += 1
                maxLen = max(maxLen, l-n)
        return maxLen