// https://leetcode.com/problems/max-consecutive-ones-iii/
// Medium
// June 29th, 2021 Challenge

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, maxSum = 0;
        int size = nums.size();
        while (end < size) {
            if (nums[end] == 0) {
                if (k > 0) {
                    --k;
                    ++end;
                    maxSum = max(maxSum, end-start);
                } else {
                    if (nums[start] == 0) {
                        ++k;
                    }
                    start++;
                }
            } else {
                ++end;
                maxSum = max(maxSum, end-start);
            }
        }
        return maxSum;
    }
};