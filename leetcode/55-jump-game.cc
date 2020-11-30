// https://leetcode.com/problems/jump-game/
// Medium

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max + 1 >= nums.size()) {
            return true;
            } else if (nums[i] == 0 && max <= i) {
                return false;
            }
            max = i + nums[i] > max ? i + nums[i] : max;
        }
        return false;
    }
};