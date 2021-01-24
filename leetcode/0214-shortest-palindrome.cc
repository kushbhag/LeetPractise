// https://leetcode.com/problems/shortest-palindrome/
// Hard
#include<string>
using namespace std;

// TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len == 0) return "";
        int currPalindromeLen = INT_MAX;
        int indexPalindrome;
        bool even = false;
        for (int i = 0; i < len/2 + 1; ++i) {
            int lo = i-1, hi = i+1;
            bool palindrome = true;
            int tempLen = 1;
            //cout << currPalindrome << endl;
            while (hi < len) {
                if (lo < 0) {
                    tempLen += 2*(len-hi);
                    break;
                } else if (s[hi] != s[lo]) {
                    palindrome = false;
                    break;
                } else {
                    tempLen += 2;
                }
                ++hi;
                --lo;
            }
            if (palindrome && lo < 0 && tempLen < currPalindromeLen) {
                currPalindromeLen = tempLen;
                indexPalindrome = i;
                even = false;
            }
            lo = i;
            hi = i+1;
            palindrome = true;
            tempLen = 0;
            while (hi < len) {
                if (lo < 0) {
                    tempLen += 2*(len-hi);
                    break;
                } else if (s[hi] != s[lo]) {
                    palindrome = false;
                    break;
                } else {
                    tempLen += 2;
                }
                ++hi;
                --lo;
            }
            if (palindrome && lo < 0 && tempLen < currPalindromeLen) {
                currPalindromeLen = tempLen;
                indexPalindrome = i;
                even = true;
            }
        }
        //cout << indexPalindrome << endl;
        int lo = indexPalindrome-1;
        int hi = indexPalindrome+1;
        string ss = "";
        ss += s[indexPalindrome];
        if (even) {
            lo = indexPalindrome;
            hi = indexPalindrome+1;
            ss = "";
        }
        //cout << indexPalindrome << endl;
        
        while (hi < len) {
            if (lo < 0) {
                ss = s[hi] + ss + s[hi];
            } else {
                ss = s[lo] + ss + s[hi];
            }
            ++hi;
            --lo;
        }
        return ss;
    }
};