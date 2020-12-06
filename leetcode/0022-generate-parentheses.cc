// https://leetcode.com/problems/generate-parentheses/
// Medium

#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        generateParenthesisNum(s, n, 0, "");
        return s;
    }
    void generateParenthesisNum(vector<string>& ret, int n, int remaining, string s) {
        if (n == 0 && remaining == 0) {
            ret.push_back(s);
            return;
        }
        if (n > 0) generateParenthesisNum(ret, n-1, remaining-1, s+")");
        if (remaining > 0) generateParenthesisNum(ret, n, remaining+1, "("s);
    }
};