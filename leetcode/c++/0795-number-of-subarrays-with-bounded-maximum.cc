// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Medium
// June 17th, 2021 Challenge

#include<vector>

using namespace std;


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size(), count = 0, temp = 0, maxSoFar = 0;
        int lowCount = 0;
        for (int i = 0; i < size; ++i) {
            maxSoFar = max(maxSoFar, nums[i]);
            
            if (nums[i] <= right) {
                temp++;
                if (maxSoFar >= left && maxSoFar <= right) {
                    if (nums[i] < left) {
                        lowCount++;
                    } else {
                        lowCount = 0;
                    }
                    count -= lowCount;
                    count += temp;
                }
            } else {
                maxSoFar = 0;
                temp = 0;
            }
            
        }
        return count;
    }
};

// Dynamic Programming Solution
// TLE
class Solution1 {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size(), count = 0;
        vector<int> v (nums.begin(), nums.end());
        for (int &x: nums) {
            if (x >= left && x <= right) count++;
        }
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < size-i; ++j) {
                v[j] = max(v[j], v[j+1]);
                if (v[j] >= left && v[j] <= right) count++;
            }
        }
        return count;
    }
};