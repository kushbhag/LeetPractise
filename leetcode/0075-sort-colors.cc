// https://leetcode.com/problems/sort-colors/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, size = nums.size(), hi = size-1;

        for (int i = 0; i <= hi; ++i) {
            while (nums[lo] == 0 && ++lo < size) { }
            while (nums[hi] == 2 && --hi >= 0) { }
            i = max(lo, i);
            if (lo >= size || hi < 0 || i > hi) return;
            if (nums[i] == 0) {
                swap(nums[i], nums[lo]);
                if (nums[i] == 2) --i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[hi]);
                if (nums[i] == 0) --i;
            }
        }
    }
};