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

class Solution1 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int total = 0;
        for (int&n : nums) {
            total = n < k ? total+1 : total;
        }
        int lo = 0, hi = 1;
        int product = nums[0];
        while (hi < size) {
            if (lo == hi) {
                ++hi;
                product *= nums[lo];
            } else if (product*nums[hi] < k) {
                product *= nums[hi];
                total += (hi-lo-1) + 1;
                ++hi;
            } else {
                product /= nums[lo];
                ++lo;
            }
            
        }
        
        //total += max (size - lo - 2, 0);
        return total;
    }
};