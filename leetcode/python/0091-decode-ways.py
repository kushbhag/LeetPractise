# https://leetcode.com/problems/decode-ways/
# Medium

# Create a set that contains all the mappings from string 1..26
# Go backwards (or forwards) in the string, at each point checking if the
#  current character or the two consecutive characters belong in the set
# If they do, add the dp value of the corresponding index
class Solution:
    def numDecodings(self, s: str) -> int:
        d = set(str(i) for i in range(1, 27))
        dp = [0]*(len(s)+1)
        dp[-1] = 1
        dp[-2] = 1 if s[-1] != '0' else 0
        for i in range(len(s)-2, -1, -1):
            if s[i:i+1] in d:
                dp[i] += dp[i+1]
            if s[i:i+2] in d:
                dp[i] += dp[i+2]
        return dp[0]
        