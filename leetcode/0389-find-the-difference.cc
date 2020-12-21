// https://leetcode.com/problems/find-the-difference/
// Easy

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alpha (26, 0);
        for (char &c: s) {
            ++alpha[c-'a'];
        }
        for (char &c: t) {
            if (--alpha[c-'a'] < 0) return c;
        }
        return t[0];
    }
};