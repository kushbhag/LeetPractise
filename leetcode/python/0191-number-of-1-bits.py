# https://leetcode.com/problems/number-of-1-bits/
# Easy

# Better solution is to use 'n &= n-1'
# This will essentially drop the rightmost 1 bit everysingle time
# Ends up being faster because you only iterate for the number of 1's you have
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            n &= n-1
            count += 1
        return count

# Bit shift every time
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            if n & 1 == 1: count += 1
            n >>= 1
        return count