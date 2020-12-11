// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Easy

#include<vector>

using namespace std;

class Solution {
    int buy, sell, size, gain = 0;
public:
    Solution() {
        buy = 0;
        sell = 1;
        gain = 0;
    }
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        for (;sell < size; ++sell) {
            gain = prices[sell] - prices[buy] > gain ? prices[sell] - prices[buy] : gain;
            if (prices[buy] > prices[sell]) {
                buy = sell;
            }
        }
        return gain;
    }
};