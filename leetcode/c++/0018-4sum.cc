// https://leetcode.com/problems/4sum/
// Medium
// July 16th, 2021 Challenge

#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());
        
    }

    vector<vector<int>> twoSum(vector<vector<int>>& nums, int target) {
        unordered_map<int, int> m;
        vector<vector<int>> ret;
        for (vector<int>& v: nums) {
            m[v[0]]++;
        }
        for (vector<int>& v: nums) {
            if (m[target - v[0]] > 1) {
                ret.push_back()
            }
        }
    }
};