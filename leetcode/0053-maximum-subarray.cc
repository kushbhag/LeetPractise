// https://leetcode.com/problems/maximum-subarray/
// Easy
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], size = nums.size(), curr = max(nums[0], 0);
        for (int i = 1; i < size; ++i) {
            maxSoFar = max(maxSoFar, curr + nums[i]);
            curr = max(curr+nums[i], 0);
        }
        return maxSoFar;
    }
};