# https://leetcode.com/problems/word-break/
# Medium

# Should be a O(len(s) * len(wordDict)) solution
# You can start at the end of s or at the beginning, and check if
#   The word you are currently seeing is in wordDict
#   If it is, then dp[i] = True, and then check the next character
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [True]+[False]*len(s)
        
        for i in range(1, len(s)+1):
            for word in wordDict:
                if i-len(word) >= 0 and dp[i-len(word)] and s[:i].endswith(word):
                    dp[i] = True
                    break
        return dp[-1]