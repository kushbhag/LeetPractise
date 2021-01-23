// https://leetcode.com/problems/intersection-of-two-arrays/
// Easy
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s (nums1.begin(), nums1.end());
        unordered_set<int> s1;
        vector<int> ret;
        for (int&n: nums2) {
            if (s.find(n) != s.end() && s1.find(n) == s1.end()) {
                s1.insert(n);
                ret.push_back(n);
            }
        }
        return ret;
    }
};