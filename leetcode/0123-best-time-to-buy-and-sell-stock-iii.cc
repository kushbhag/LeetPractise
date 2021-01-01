// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Hard

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSoFar = -prices[0], size = prices.size();
        vector<vector<int>> v (3, vector<int> (size, 0));
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j < size; ++j) {
                v[i][j] = max(v[i][j-1], prices[j] + maxSoFar);
                maxSoFar = max(maxSoFar, v[i-1][j] - prices[j]);
            }
            maxSoFar = -prices[0];
        }
        return v[2][size-1];
    }
};