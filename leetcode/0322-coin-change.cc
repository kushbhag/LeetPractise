// https://leetcode.com/problems/coin-change/
// Medium

#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> v (amount+1, -1);
        int temp;
        for (int i = 1; i <= amount; ++i) {
            temp = INT_MAX;
            for (int &n: coins) {
                if (n-i == 0) {
                    temp = 1;
                    break;
                } 
                if (i-n > 0 && v[i-n] != -1) {
                    temp = min(temp, v[i-n] + 1);
                }
            }
            v[i] = temp == INT_MAX ? -1 : temp;
            //cout << i << ' ' << v[i] << endl;
        }
        return v[amount];
    }
};