// https://leetcode.com/problems/contains-duplicate/
// Easy

#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int &n: nums) {
            if (s.find(n) == s.end()) {
                s.insert(n);
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution1 {
    int len;
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        len = nums.size();
        for (int i = 1; i < len; ++i) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};