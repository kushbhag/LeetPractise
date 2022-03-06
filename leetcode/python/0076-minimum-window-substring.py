# https://leetcode.com/problems/minimum-window-substring/
# Hard

from collections import Counter

# Use a counter to keep track of all the counts in t
# tDic can remain positive or negative
# Also have a 'missing' count that counts the number of characters that are missing from t that have yet to be checked
# 'missing -= tDic[c] > 0' is the key line
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tDic = Counter(t)
        lo, minWindow, missing = 0, inf, len(t)
        smallest = ''

        for i, c in enumerate(s):
            missing -= tDic[c] > 0
            tDic[c] -= 1
            if missing == 0:
                while s[lo] not in tDic or tDic[s[lo]] < 0:
                    tDic[s[lo]] += s[lo] in tDic
                    lo += 1
                if i-lo+1 < minWindow:
                    minWindow = i-lo+1
                    smallest = s[lo : lo+minWindow]
                missing += 1
                tDic[s[lo]] += 1
                lo += 1
            
        return smallest

