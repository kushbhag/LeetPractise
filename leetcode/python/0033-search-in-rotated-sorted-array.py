# https://leetcode.com/problems/search-in-rotated-sorted-array/
# Medium

# Check if nums[lo] <= nums[mid]
#   Then check if target is between nums[lo] and nums[mid]
#   And reduce hi accordingly
# Else
#   Check if target is between nums[mid] and nums[hi]
#   If it is then increase lo accordingly
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums) - 1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            if target == nums[mid]:
                return mid
            
            if nums[lo] <= nums[mid]:
                if nums[lo] <= target <= nums[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            else:
                if nums[mid] <= target <= nums[hi]:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return -1
                
        