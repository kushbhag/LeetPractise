// https://leetcode.com/problems/majority-element/
// Easy

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int majority;
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        majority = nums.size() / 2;
        for (int &n: nums) {
            if (++m[n] > majority) return n;
        }
        return nums[0];
    }
};