// https://leetcode.com/problems/subsets/
// Medium

#include<vector>

using namespace std;

class Solution {
    int size;
    void dfs(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& v) {
        if (start > size) return;
        v.push_back(temp);
        for (int i = start; i < size; ++i) {
            temp.push_back(nums[i]);
            dfs(nums, i+1, temp, v);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        vector<vector<int>> v;
        vector<int> temp;
        dfs(nums, 0, temp, v);
        return v;
    }
};