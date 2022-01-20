// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Medium

#include<string>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int currLen = 1;
        int len = s.length();
        vector<pair<char, int>> v;
        v.push_back({s[0], 1});
        for (int i = 1; i < len; ++i) {
            if (currLen == k) {
                //cout << v.size() << ' ' << currLen << endl;
                for (int j = 0; j < k; ++j) {
                    v.pop_back();
                }
            }
            if (!v.empty() && s[i] == v.back().first) {
                currLen = v.back().second + 1;
                v.push_back({s[i], currLen});
            } else {
                currLen = 1;
                v.push_back({s[i], currLen});
            }
        }
        if (currLen == k) {
            for (int j = 0; j < k; ++j) {
                v.pop_back();
            }
        }
        string ret;
        for (pair<char, int>& p: v) {
            ret.push_back(p.first);
        }
        return ret;
    }
};