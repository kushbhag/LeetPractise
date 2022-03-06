# https://leetcode.com/problems/climbing-stairs/
# Easy

class Solution:
    def climbStairs(self, n: int) -> int:
        two, one = 0, 1
        for i in range(n):
            curr = one + two
            two, one = one, curr
        return curr
        