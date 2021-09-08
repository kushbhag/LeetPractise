// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Medium

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> v (26, 0);
        for (char &c: s) {
            v[c-'a']++;
        }
        int len = s.length();
        vector<bool> check (len+1, false);
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            while (v[i] != 0 && check[v[i]]) {
                v[i]--;
                count++;
            }
            check[v[i]] = true;
        }
        return count;
    }
};