// https://leetcode.com/problems/find-the-duplicate-number/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> dups (nums.size()-1, false);
        for (auto &n: nums) {
            if (dups[n]) {
                return n;
            } else {
                dups[n] = true;
            }
        }
        return -1;
    }
};