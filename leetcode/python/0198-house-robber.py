# https://leetcode.com/problems/house-robber/
# Medium

# Easy to understand, but more time consuming
# Bottom one is better
class Solution:
    def rob(self, nums: List[int]) -> int:
        nums = [0,0] + nums
        for i in range(2, len(nums)):
            nums[i] = max(nums[i]+nums[i-2], nums[i-1])
        return nums[-1]

# Use a DP with O(1) memory to keep track of current max
class Solution:
    def rob(self, nums: List[int]) -> int:
        prev, curr = 0, 0
        for n in nums:
            curr, prev = max(prev+n, curr), curr
        return curr