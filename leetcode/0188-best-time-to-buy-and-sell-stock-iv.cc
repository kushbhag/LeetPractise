// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Hard

#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;
        int maxSoFar = -prices[0];
        vector<vector<int>> v (k+1, vector<int> (size, 0));
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < size; ++j) {
                v[i][j] = max(v[i][j-1], prices[j] + maxSoFar);
                maxSoFar = max(maxSoFar, v[i-1][j] - prices[j]);
                //cout << v[i][j] << ' ';
            }
            //cout << endl;
            maxSoFar = -prices[0];
        }
        return v[k][size-1];
    }
};