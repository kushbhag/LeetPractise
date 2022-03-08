# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Easy

# Keep track of smallest price so far, and continuously compare current price with smallest price
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret, smallest = 0, prices[0]
        for n in prices[1:]:
            smallest = min(smallest, n)
            ret = max(ret, n-smallest)
        return ret