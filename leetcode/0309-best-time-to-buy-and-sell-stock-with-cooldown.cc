// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currBuyMax = INT_MIN, currSellMax = 0;
        int prevBuy, prevSell = 0, prevprevSell = 0;
        for (int i =0; i < prices.size(); ++i) {
            prevBuy = currBuyMax;
            prevSell = currSellMax;

            currBuyMax = max (prevBuy, prevprevSell - prices[i]);
            currSellMax = max (prevSell, prevBuy + prices[i]);

            if (i != 0) {
                prevprevSell = prevSell;
            }
        }
        return currSellMax;
    }
};