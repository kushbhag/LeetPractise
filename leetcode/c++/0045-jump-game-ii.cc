// https://leetcode.com/problems/jump-game-ii/
// Medium

#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> v (size, 10000);
        int maxSoFar = 0;
        v[0] = 0;
        for (int i = 0; i < size-1; ++i) {
            int steps = nums[i];
            int curr = v[i] + 1;
            for (int j = maxSoFar+1; j <= steps+i && j < size; ++j) {
                v[j] = min(v[j], curr);
            }
            maxSoFar = max(maxSoFar, steps+i);
        }
        return v[size-1];
    }
};