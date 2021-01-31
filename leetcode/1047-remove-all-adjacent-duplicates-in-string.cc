// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Easy

#include<string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int currLen = 1;
        int len = s.length();
        string ret;
        for (int i = 0; i < len; ++i) {
            if (!ret.empty() && ret.back() == s[i]) {
                ret.pop_back();
            } else {
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};