// https://leetcode.com/problems/maximum-product-subarray/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0], currMax = nums[0], currMin = nums[0], prevMax = 1, size = nums.size();
        for (int i = 1; i < size; ++i) {
            currMax = max (nums[i], max (prevMax * nums[i], currMin * nums[i]));
            currMin = min (nums[i], min (prevMax * nums[i], currMin * nums[i]));
            maxSoFar = max (maxSoFar, currMax);
            prevMax = currMax;
            // currP = max (1, max(nums[i] * currP, currN));
            // cout << maxSoFar << ' ' << currN << ' ' << currP << endl;
        }
        return maxSoFar;
    }
};