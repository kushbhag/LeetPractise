// https://leetcode.com/problems/two-sum/
// Easy

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int size;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        size = nums.size();
        for (int i = 0; i < size; ++i) {
            memo[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i) {
            if (memo.find(target-nums[i]) != memo.end() && memo[target-nums[i]] != i) {
                return vector<int> {i, memo[target-nums[i]]};
            }
        }
        return vector<int> ();
    }
};