// https://leetcode.com/problems/remove-invalid-parentheses/
// Hard

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
    vector<string> mem;
    unordered_set<string> storedStrings;
    int len;
    int minRemoved = INT_MAX;
    void removeInvalidParenthesesRec(string s, int index, int leftParen, int rightParen, string& currString, int removed) {
        if (leftParen == rightParen && index == len && storedStrings.find(currString) == storedStrings.end()) {
            if (removed == minRemoved) {
                mem.push_back(currString);
                storedStrings.insert(currString);
            } else if (removed < minRemoved) {
                mem.clear();
                minRemoved = removed;
                mem.push_back(currString);
                //storedStrings.clear();
                storedStrings.insert(currString);
            }
            return;
        }
        if (index == len) return;
        if (s[index] == '(') {
            removeInvalidParenthesesRec(s, index+1, leftParen, rightParen, currString, removed+1);
            currString.push_back('(');
            removeInvalidParenthesesRec(s, index+1, leftParen+1, rightParen, currString, removed);
            currString.pop_back();
        } else if (s[index] == ')') {
            removeInvalidParenthesesRec(s, index+1, leftParen, rightParen, currString, removed+1);
            if (leftParen > rightParen) {
                currString.push_back(')');
                removeInvalidParenthesesRec(s, index+1, leftParen, rightParen+1, currString, removed);
                currString.pop_back();
            }
        } else {
            currString.push_back(s[index]);
            removeInvalidParenthesesRec(s, index+1, leftParen, rightParen, currString, removed);
            currString.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        len = s.length();
        string ss = "";
        removeInvalidParenthesesRec(s, 0, 0, 0, ss, 0);
        return mem;
    }
};