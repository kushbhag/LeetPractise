// https://leetcode.com/problems/is-subsequence/
// Easy

#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length();
        if (len1 > t.length()) return false;
        if (len1 == 0) return true;

        int j = 0;
        for (char &c: t) {
            if (s[j] == c) {
                if (++j >= len1) return true;
                //cout << j << ' ' << len1 << endl;
            }
        }
        return false;;
    }
};