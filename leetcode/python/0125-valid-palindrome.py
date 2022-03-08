# https://leetcode.com/problems/valid-palindrome/
# Easy

# Short solution
class Solution:
    def isPalindrome(self, s: str) -> bool:
        chars = "".join([c for c in s if c.isalnum()]).lower()
        return chars == chars[::-1]
# Using filter
class Solution:
    def isPalindrome(self, s: str) -> bool:
        chars = "".join(filter(str.isalnum, s.lower()))
        return chars == chars[::-1]

# Two pointer solution
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        lo, hi = 0, len(s)-1
        while lo < hi:
            if not s[lo].isalnum():
                lo += 1
            elif not s[hi].isalnum():
                hi -= 1
            elif s[lo] != s[hi]:
                return False
            else:
                lo += 1
                hi -= 1
        return True