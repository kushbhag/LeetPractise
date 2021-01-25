// https://leetcode.com/problems/generate-parentheses/
// Medium

#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
    void generateParenthesisRec(int n, int remaining, string s, vector<string>& ret) {
        if (n == 0 && remaining == 0) {
            ret.push_back(s);
            return;
        }
        if (remaining > 0) generateParenthesisRec(n, remaining-1, s+")", ret);
        if (n > 0) generateParenthesisRec(n-1, remaining+1, s+"(", ret);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s = "";
        generateParenthesisRec(n, 0, s, ret);
        return ret;
    }
};