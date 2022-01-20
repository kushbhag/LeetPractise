// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Medium

#include<string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int currCount = 0;
        string ret;
        for (char &c: s) {
            if (c == '(') {
                ++currCount;
                ret.push_back(c);
            } else if (c == ')') {
                if (currCount > 0) {
                    --currCount;
                    ret.push_back(c);
                }
            } else {
                ret.push_back(c);
            }
        }
        for (int i = 0; i < currCount; ++i) {
            ret.pop_back();
        }
        return ret;
    }
};