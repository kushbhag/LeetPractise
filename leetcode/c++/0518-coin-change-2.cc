// https://leetcode.com/problems/coin-change-2/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

// O(N) memory
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<int> v (amount + 1, 0);
        vector<int> prev (amount + 1, 0);
        v[0] = 1;
        prev[0] = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] == j) {
                    v[j] = 1 + prev[j];
                } else if (coins[i] < j) {
                    v[j] = v[j-coins[i]] + prev[j];
                } else {
                    v[j] = prev[j];
                }
            }
            prev = v;
        }
        return v[amount];
    }
};

// A little more optimized O(N) memory
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> v (amount + 1, 0);
        v[0] = 1;
        for (int &c: coins) {
            for (int j = 1; j <= amount; ++j) {
                if (c <= j) {
                    v[j] += v[j-c];
                }
            }
        }
        return v[amount];
    }
};