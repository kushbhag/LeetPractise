// https://leetcode.com/problems/word-break-ii/
// Hard
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> m;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return vector<string> {""};
        }
        if (m.find(s) != m.end()) return m[s];
        vector<string> v;
        int len = s.length();
        for (string& temp: wordDict) {
            if (temp == s.substr(0, temp.length())) {
                if (s.substr(temp.length(), len).empty()) {
                    v.push_back(temp);
                } else {
                    string add = temp + " ";
                    vector<string> ret = wordBreak(s.substr(temp.length(), len), wordDict);
                    for (string& retStr: ret) {
                        v.push_back(add + retStr);
                    }
                }
            }
        }
        m[s] = v;
        return v;
    }
};