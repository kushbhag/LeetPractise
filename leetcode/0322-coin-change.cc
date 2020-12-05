// https://leetcode.com/problems/coin-change/
// Medium

#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo (amount+1, -1);
        memo[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int minCoins = INT_MAX;
            for (int &c: coins) {
                if (i-c >= 0 && memo[i-c] != -1) {
                    minCoins = memo[i-c] + 1 < minCoins ? memo[i-c] + 1 : minCoins;
                }
            }
            if (minCoins != INT_MAX) memo[i] = minCoins;
        }
        return memo[amount];
    }
};