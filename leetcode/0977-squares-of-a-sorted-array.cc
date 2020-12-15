// https://leetcode.com/problems/squares-of-a-sorted-array/
// Easy

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int size, lo, hi = 0;
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        size = nums.size();
        lo = size - 1;
        hi = size;

        for (int i = 1; i < size; ++i) {
            if (-nums[i-1] <= nums[i]) {
                lo = i-1;
                hi = i;
                break;
            }
        }
        while (lo >= 0 || hi < size) {
            if (lo < 0) {
                ret.push_back(nums[hi] * nums[hi++]);
            } else if (hi >= size) {
                ret.push_back(nums[lo] * nums[lo--]);
            } else {
                ret.push_back(abs(nums[lo]) > abs(nums[hi]) ? nums[hi] * nums[hi++]: nums[lo] * nums[lo--]);
            }
        }
        return ret;
    }
};