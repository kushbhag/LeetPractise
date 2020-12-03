// https://leetcode.com/problems/maximum-subarray/
// Easy
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p = 0, max = nums[0], size = nums.size(), tempCount = 0;
        while (p++ < size) {
            tempCount = tempCount + nums[p] < nums[p] ? nums[p] : tempCount + nums[p];
            if (tempCount > max){
                max = tempCount;
            }
        }
        return max;
    }
};