// https://leetcode.com/problems/palindrome-partitioning/
// Medium
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

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