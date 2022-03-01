# https://leetcode.com/problems/jump-game/
# Medium

# Just have a variable that keeps track of the max jump reachable
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump = 0
        for i,n in enumerate(nums):
            if i > maxJump:
                return False
            maxJump = max(i+n, maxJump)
        return True