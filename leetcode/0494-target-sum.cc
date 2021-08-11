// https://leetcode.com/problems/target-sum/
// Medium

#include<vector>

using namespace std;

class Solution {
    int ways = 0;
    int size;
    void findTargetSumWays(vector<int>& nums, int target, int sum, int index) {
        if (sum < target) return;
        if (sum == target) {
            ++ways;
            return;
        }
        for (int i = index; i < size; ++i) {
            if (nums[i] != 0) findTargetSumWays(nums, target, sum-(2*nums[i]), i+1);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, countZero = 1;
        for (int &x: nums) {
            sum += x;
            if (x == 0) countZero++;
        }
        size = nums.size();
        findTargetSumWays(nums, target, sum, 0);
        for (int i = 1; i < countZero; ++i) {
            ways *= 2;
        }
        return ways;
    }
};