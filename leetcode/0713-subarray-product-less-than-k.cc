// https://leetcode.com/problems/subarray-product-less-than-k/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int size = nums.size(), count = 0;
        int left = 0, product = 1;
        for (int right = 0; right < size; ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};