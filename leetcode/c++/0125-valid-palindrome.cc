// https://leetcode.com/problems/valid-palindrome/
// Easy

#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int lo = -1, len = s.length(), hi = len;
        bool loAl = false, hiAl = false;
        while (lo < hi) {
            while (lo < len && !isalnum(s[++lo])) { }
            if (lo == len) return true;
            while (!isalnum(s[--hi])) { }

            if (tolower(s[lo]) != tolower(s[hi])) {
                return false;
            }
        }
        return true;
    }
};