# https://leetcode.com/problems/longest-palindromic-substring/
# Medium

class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = [[0]*len(s) for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = True
        
        maxLen = 1
        ret = s[0]
        for i in range(1, len(s)):
            for j in range(len(s)-i):
                k = j+i
                if s[j] == s[k] and (dp[j+1][k-1] or k-j == 1):
                    dp[j][k] = True
                    if i+1 > maxLen:
                        maxLen = i+1
                        ret = s[j:k+1]
        return ret
