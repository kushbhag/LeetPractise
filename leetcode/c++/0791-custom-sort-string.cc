// https://leetcode.com/problems/custom-sort-string/
// Medium
// July 14th, 2021 Challenge

#include<string>
#include<algorithm>
using namespace std;

class Solution {
    int sortOrder [26];
public:
    string customSortString(string order, string s) {
        for (int i = 0; i < 26; ++i) sortOrder[i] = INT_MAX;
        int len = order.length();
        for (int i = 0; i < len; ++i) {
            sortOrder[order[i]-'a'] = i;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return sortOrder[a-'a'] < sortOrder[b-'a'];
        });
        return s;
    }
};