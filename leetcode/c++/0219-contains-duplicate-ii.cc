// https://leetcode.com/problems/contains-duplicate-ii/
// Easy

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                //cout << nums[i] << ' ' << i << ' ' << m[nums[i]] << endl;
                return true;
            } else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};