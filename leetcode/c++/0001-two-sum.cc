// https://leetcode.com/problems/two-sum/
// Easy

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i) {
                return vector<int> {m[target-nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return vector<int> ();
    }
};