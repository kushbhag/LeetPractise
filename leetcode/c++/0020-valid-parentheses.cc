// https://leetcode.com/problems/valid-parentheses/
// Easy

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (char &c: s) {
            if (c == '(') {
                v.push_back(')');
            } else if (c == '[') {
                v.push_back(']');
            } else if (c == '{') {
                v.push_back('}');
            } else if (v.size() == 0 || v.back() != c) {
                return false;
            } else {
                v.pop_back();
            }
        }
        return v.size() == 0;
    }
};