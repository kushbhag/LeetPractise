// https://leetcode.com/problems/palindrome-partitioning/
// Medium
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Original
class Solution {
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    vector<vector<string>> partitionMemo(string s, unordered_map<string, vector<vector<string>>>& memo) {
        vector<vector<string>> v;
        if (memo.find(s) != memo.end()) {
            return memo[s];
        } else if (s == "") {
            v.emplace_back(vector<string> (0));
            return v;
        }
        // cout << s << endl;
        int size =  s.length();
        for (int i = 1; i <= size; ++i) {
            string start = s.substr(0,i);
            if (isPalindrome(start)) {
                vector<vector<string>> temp = partitionMemo(s.substr(i,size), memo);
                if (temp.size() > 0) {
                    for (vector<string> &pal: temp) {
                        pal.push_back(start);
                        v.push_back(pal);
                    }
                }
            }
        }
        memo[s] = v;
        return v;
    }
public:
    vector<vector<string>> partition(string s) {
        unordered_map<string, vector<vector<string>>> m;
        vector<vector<string>> ret = partitionMemo(s, m);
        for (vector<string>& v: ret) {
            reverse(v.begin(), v.end());
        }
        return ret;
    }
};

// Dynamic Programming
class Solution {
    int len;
    vector<vector<bool>> v;
    void partitionRec(string s, int start, vector<string>& temp, vector<vector<string>>& ret) {
        //cout << start;
        if (start >= len) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i < len; ++i) {
            if (v[start][i]) {
                temp.push_back(s.substr(start, i-start+1));
                //cout << s.substr(start, i-start+1) << endl;
                partitionRec(s, i+1, temp, ret);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        len = s.length();
        v = vector<vector<bool>> (len+1, vector<bool> (len, false));
        int hi;
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i+j < len; ++i) {
                hi = i+j;
                if (s[i] == s[hi] && (j <= 1 || v[i+1][hi-1])) {
                    //cout << i << " " << hi << endl;
                    v[i][hi] = true;
                }
            }
        }
        // for (int i = 0; i < len; ++i) {
        //     for (int j = 0; j < len; ++j) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<string> temp;
        vector<vector<string>> ret;
        partitionRec(s, 0, temp, ret);
        return ret;
    }
};

// Using Recursion
// Slower because it doesn't use memory
class Solution {
    int len;
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    void partitionRec(string s, int start, vector<string>& temp, vector<vector<string>>& v) {
        if (start >= len) {
            v.push_back(temp);
            return;
        }
        for (int i = start+1; i <= len; ++i) {
            string check = s.substr(start, i-start);
            if (isPalindrome(check)) {
                temp.push_back(check);
                partitionRec(s, i, temp, v);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        len = s.length();
        vector<vector<string>> v;
        vector<string> temp;
        partitionRec(s, 0, temp, v);
        return v;
    }
};