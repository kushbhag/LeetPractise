// https://leetcode.com/problems/permutations-ii/
// Medium

#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// Using unordered_set
class Solution {
    int size;
    void permuteRec(vector<int>& nums, int start, vector<vector<int>>& v) {
        if (start >= size) return;
        permuteRec(nums, start+1, v);
        unordered_set<int> s;
        for (int i = start+1; i < size; ++i) {
            swap(nums[start], nums[i]);
            if (nums[start] != nums[i] && s.find(nums[start]) == s.end()) {
                v.push_back(nums);
                s.insert(nums[start]);
                permuteRec(nums, start+1, v);
            }
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        size = nums.size();
        vector<vector<int>> v;
        v.push_back(nums);
        permuteRec(nums, 0, v);
        return v;
    }
};
