// https://leetcode.com/problems/wildcard-matching/
// Hard

#include<string>
#include<vector>

using namespace std;

class Solution {
    int len1, len2;
public:
    bool isMatch(string s, string p) {
        len1 = s.length();
        len2 = p.length();
        vector<vector<bool>> v (len2+1, vector<bool> (len1+1, false));
        for (int i = 0; i <= len2; ++i) {
            v[i][0] = true;
            if (p[i] != '*') break;
        }
        bool check;
        for (int i = 0; i < len2; ++i) {
            check = false;
            for (int j = 0; j < len1; ++j) {
                if (p[i] == '*' && (v[i][j] || v[i][j+1] || check)) {
                    v[i+1][j+1] = true;
                    check = true;
                }
                else if (p[i] == '?' && v[i][j]) v[i+1][j+1] = true;
                else if (p[i] == s[j] && v[i][j]) v[i+1][j+1] = true;
            }
        }
        return v[len2][len1];
    }
};