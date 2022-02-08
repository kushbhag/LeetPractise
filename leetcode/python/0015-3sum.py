# https://leetcode.com/problems/3sum/
# Medium

# Two Sum Solution
# Quicker and more memory efficient
class SolutionTwoSum:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def twoSum(nums: List[int], target: int, start: int) -> List[List[int]]:
            lo, hi = start, len(nums)-1
            ret = []
            while lo < hi:
                if nums[lo]+nums[hi]+target > 0:
                    hi -= 1
                elif nums[lo]+nums[hi]+target < 0:
                    lo += 1
                else:
                    ret.append([nums[lo], nums[hi], target])
                    lo += 1
                    while lo < hi and nums[lo] == nums[lo-1]:
                        lo += 1
            return ret
        
        nums.sort()
        ret = []
        for i, n in enumerate(nums):
            if n > 0:
                break
            if i == 0 or nums[i] > nums[i-1]:
                ret += twoSum(nums, n, i+1) 

        return ret

# Set solution
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        d = {}
        ret = []
        for i, n in enumerate(nums):
            d[n] = i
        
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, len(nums)):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                find = -(nums[i] + nums[j])
                if find in d and d[find] > j:
                    ret.append([nums[i], nums[j], find])

        return ret