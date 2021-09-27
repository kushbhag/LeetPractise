// https://leetcode.com/problems/range-sum-query-immutable/
// Easy

#include<vector>

using namespace std;

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int size = nums.size(), sum = 0;
        sums = vector<int> (size, 0);
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return sums[right];
        return sums[right] - sums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */