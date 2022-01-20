// https://leetcode.com/problems/longest-common-prefix/
// Easy

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ret = "";
        int maxLen = INT_MIN;
        int temp;
        for (string &s: strs) {
            temp = s.length();
            if (temp == 0) return "";
            maxLen = temp > maxLen ? temp : maxLen;
        }
        for (int i = 0; i < maxLen; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) return ret;
            }
            ret += strs[0][i];
        }
        return ret;
    }
};