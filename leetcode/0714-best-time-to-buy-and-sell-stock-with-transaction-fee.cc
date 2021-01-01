// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int currBuyMax = INT_MIN+fee, currSellMin = 0;
        int prevBuyMax, prevSellMin;
        for (int &n: prices) {
            prevBuyMax = currBuyMax;
            prevSellMin = currSellMin;

            currBuyMax = max(prevBuyMax, prevSellMin - n);
            currSellMin  = max(prevSellMin, prevBuyMax + n - fee);
        }
        return currSellMin;
    }
};