// https://leetcode.com/problems/next-permutation/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size-2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i+1;
        for (; j < size; ++j) {
            if (nums[j] <= nums[i]) {
                --j;
                break;
            }
        }
        if (j == size) --j;
        //cout << j << ' ' << i << endl;
        swap(nums[j], nums[i]);
        reverse(nums.begin()+i+1, nums.end());
    }
};