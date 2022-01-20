// https://leetcode.com/problems/valid-anagram/
// Easy

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if (len != t.length()) return false;
        vector<int> v (26, 0);
        for (int i = 0; i < len; ++i) {
            ++v[s[i]-'a'];
            --v[t[i]-'a'];
        }
        for (int &n: v) {
            if (n != 0) return false;
        }
        return true;
    }
};