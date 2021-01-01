// https://leetcode.com/problems/jump-game/
// Medium

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxSoFar = nums[0], size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (maxSoFar >= size-1) return true;
            if (i > maxSoFar) return false;
            maxSoFar = maxSoFar < i + nums[i] ? i + nums[i] : maxSoFar;
        }
        return false;
    }
};