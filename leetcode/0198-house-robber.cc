// https://leetcode.com/problems/house-robber/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> mem (size+2, 0);
        for (int i = 0; i < size; ++i) {
            mem[i+2] = max(nums[i] + mem[i], mem[i+1]);
        }
        return mem[size+1];
    }
};