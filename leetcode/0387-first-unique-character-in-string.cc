// https://leetcode.com/problems/first-unique-character-in-a-string/
// Easy
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v (26, 0);
        for (char &c: s) {
            v[c-'a']++;
        }
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (v[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};