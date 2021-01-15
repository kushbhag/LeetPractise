// https://leetcode.com/problems/valid-palindrome-ii/
// Easy
// Mock

#include<string>

using namespace std;

class Solution {
    bool isPalindrome(string s, int lo, int hi) {
        while (lo <= hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int lo = 0, len = s.length(), hi = len-1;
        while(lo <= hi) {
            if (s[lo] != s[hi]) {
                return (isPalindrome(s, lo+1, hi) || isPalindrome(s, lo, hi-1));
            } else if (lo == hi) {
                return true;
            }
        }
        return true;
    }
};