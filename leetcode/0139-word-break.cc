// https://leetcode.com/problems/word-break/
// Medium

#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class DPSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> v (len, false);
        for (int i = len-1; i >= 0; --i) {
            for (string &w: wordDict) {
                int slen = w.length();
                if (w == s.substr(i, slen)) {
                    if (i + slen >= len || v[i+slen]) {
                        v[i] = true;
                        break;
                    }
                }
            }
        }
        return v[0];
    }
};

class Solution {
    bool wordBreakMemo(string s, vector<string>& wordDict, unordered_map<string, bool>& m) {
        if (s.empty()) return true;
        else if (m[s]) return false;
        int len = s.length();
        int lenDict = wordDict.size();
        for (int i = 0; i < len;) {
            int minJump = INT_MAX;
            for (int j = 0; j < lenDict; ++j) {
                int wordLen = wordDict[j].length();
                int minJump = min(minJump, wordLen);
                if (wordLen <= len - i &&
                    wordDict[j] == s.substr(i, wordLen)) {
                    if (wordBreakMemo(s.substr(0, i), wordDict, m) &&
                        wordBreakMemo(s.substr(i+wordLen, len), wordDict, m)) {
                        return true;
                    }
                }
            }
            i += minJump;
        }
        m[s] = true;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> m;
        return wordBreakMemo(s, wordDict, m);
    }
};