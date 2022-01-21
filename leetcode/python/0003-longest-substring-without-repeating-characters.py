# https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Medium

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lo = 0
        hi = 0
        lenSoFar = 0
        seen = set()
        while hi < len(s):
            while s[hi] in seen:
                seen.remove(s[lo])
                lo += 1
            seen.add(s[hi])
            lenSoFar = max(hi-lo+1, lenSoFar)
            hi += 1
        return lenSoFar