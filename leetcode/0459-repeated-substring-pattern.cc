// https://leetcode.com/problems/repeated-substring-pattern/
// Easy

#include<string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if (len == 1) return true;
        if (len == 2) {
            return s[0] == s[1];
        }
        int currLen = 1, lo = 0, hi = 1;
        while (hi < len) {
            if (s[hi] == s[lo]) {
                currLen = hi-lo;
                ++lo;
            } else {
                currLen = 1;
                lo = 0;
            }
            ++hi;
        }
        return lo > 0;
    }
};