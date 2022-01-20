// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Easy

#include<vector>

using namespace std;

class Solution {
    int buy, sell, size, gain;
public:
    Solution() {
        buy = 0;
        sell = 1;
        gain = 0;
    }
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        for (; sell < size; ++sell, ++buy) {
            gain = prices[sell] > prices[buy] ? gain + prices[sell] - prices[buy] : gain;
        }
        return gain;
    }
};

// Dynamic Programming Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currBuyMax = INT_MIN, currSellMin = 0;
        int prevBuyMax, prevSellMin;
        for (int &n: prices) {
            prevBuyMax = currBuyMax;
            prevSellMin = currSellMin;

            currBuyMax = max(prevBuyMax, prevSellMin - n);
            currSellMin  = max(prevSellMin, prevBuyMax + n);
        }
        return currSellMin;
    }
};