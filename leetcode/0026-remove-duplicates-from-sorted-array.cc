// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Easy

#include<vector>

using namespace std;

class Solution {
    int index = 1, compare = 0, len;
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        len = nums.size();
        for (int i = 1; i < len; ++i) {
            if (nums[compare] != nums[i]) {
                nums[index] = nums[i];
                compare = i;
                ++index;
            }
        }
        return index;
    }
};