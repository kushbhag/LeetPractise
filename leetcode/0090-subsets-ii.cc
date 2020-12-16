// https://leetcode.com/problems/subsets-ii/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
int size;
    void dfs(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& v) {
        if (start > size) return;
        v.push_back(temp);
        for (int i = start; i < size; ++i) {
            temp.push_back(nums[i]);
            dfs(nums, i+1, temp, v);
            while (i+1 < size && nums[i] == nums[i+1]) ++i;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<vector<int>> v;
        vector<int> temp;
        dfs(nums, 0, temp, v);
        return v;
    }
};