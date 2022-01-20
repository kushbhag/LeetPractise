// https://leetcode.com/problems/isomorphic-strings/
// Easy
// July 12th, 2021 Challenge

#include<string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapping [128] {0};
        bool mapping2 [128] {false};
        int len1 = s.length(), len2 = t.length();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; ++i) {
            if (mapping[s[i]] == 0) {
                if (mapping2[t[i]]) return false;
                mapping2[t[i]] = true;
                mapping[s[i]] = t[i];
            } else if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};