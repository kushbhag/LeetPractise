# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
# Medium

# Perform a binary search with lo and hi
# If nums[mid-1] >= nums[mid] <= nums[mid+1] then you found min
# Otherwise compare nums[mid] to nums[hi] and move lo and hi accordingly
class Solution:
    def findMin(self, nums: List[int]) -> int:
        lo, hi = 0, len(nums)-1
        while lo <= hi:
            mid = (lo + hi) // 2
            # ----Alternative IF statement which is cleaner but harder to grasp---
            # if nums[mid] < nums[hi]:
            #   hi = mid
            # else:
            #   lo = mid + 1

            if nums[mid-1] >= nums[mid] <= nums[(mid+1)%len(nums)]:
                return nums[mid]
            elif nums[mid] < nums[hi]:
                hi = mid - 1
            else:
                lo = mid + 1
        return -5001
                