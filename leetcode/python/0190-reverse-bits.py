# https://leetcode.com/problems/reverse-bits/
# Easy

# Continusly check for (n & 1) and append that to the back of ret
class Solution:
    def reverseBits(self, n: int) -> int:
        ret = 0
        for _ in range(32):
            ret = (ret << 1) | (n & 1)
            n >>= 1
        return ret