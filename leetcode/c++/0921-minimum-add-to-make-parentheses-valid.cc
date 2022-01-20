// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Medium

#include<string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ret = 0;
        int currCount = 0;
        for (char &c: s) {
            if (c == '(') {
                ++currCount;
            } else {
                --currCount;
            }
            if (currCount < 0) {
                ++ret;
                ++currCount;
            }
        }
        return ret + currCount;
    }
};