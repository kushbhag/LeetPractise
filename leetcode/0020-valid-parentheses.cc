// https://leetcode.com/problems/valid-parentheses/
// Easy

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        char top;
        for (char &c: s) {
            if (c == '(') {
                stack.push_back(')');
            } else if (c == '[') {
                stack.push_back(']');
            } else if (c == '{') {
                stack.push_back('}');
            } else {
                if (stack.empty() || stack.back() != c) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};