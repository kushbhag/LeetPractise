# https://leetcode.com/problems/container-with-most-water/submissions/
# Medium

class Solution:
    def maxArea(self, height: List[int]) -> int:
        lo = 0
        hi = len(height)-1
        m = 0
        while lo < hi:
            h = min(height[lo], height[hi])
            if h*(hi-lo) > m:
                m = h*(hi-lo)
            if height[lo] > height[hi]:
                hi -= 1
            else:
                lo += 1
        return m
        