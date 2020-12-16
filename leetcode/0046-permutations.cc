// https://leetcode.com/problems/permutations/
// Medium

#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    int size;
    void permuteRec(vector<int>& nums, int start, vector<vector<int>>& v) {
        if (start >= size) return;
        permuteRec(nums, start+1, v);
        for (int i = start+1; i < size; ++i) {
            swap(nums[start], nums[i]);
            v.push_back(nums);
            permuteRec(nums, start+1, v);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        vector<vector<int>> v;
        v.push_back(nums);
        permuteRec(nums, 0, v);
        return v;
    }
};