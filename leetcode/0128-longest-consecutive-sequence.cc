// https://leetcode.com/problems/longest-consecutive-sequence/
// Hard

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> m;
        for (int &n: nums) {
            m[n] = 1;
        }
        int maxLen = 1;
        int tempN = 0;
        for (int n: nums) {
            if (m.find(n-1) != m.end()) continue;
            tempN = n;
            while (m.find(n+1) != m.end()) {
                n++;
            }
            maxLen = max(maxLen, n-tempN+1);
        }
        // for (pair<int, int> p: m) {
        //     cout << p.first << ' ' << p.second << endl;
        // }
        // cout << endl;
        return maxLen;
    }
};