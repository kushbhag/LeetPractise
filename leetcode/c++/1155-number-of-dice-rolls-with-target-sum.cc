// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> v (target+1, 0);
        v[0] = 1;
        for (int i = 0; i < d; ++i) {
            vector<int> temp (target+1, 0);
            for (int j = 1; j <= f; ++j) {
                for (int k = j; k <= target; ++k) {
                    temp[k] = (temp[k] + v[k-j]) % 1000000007;
                }
            }
            swap(temp, v);
        }
        return v[target];
    }
};