// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Easy
// Mock

#include<string>

using namespace std;

class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int lo = 0, hi = s.length()-1;
        bool temp1, temp2;
        while(lo < hi) {
            temp1 = isVowel(s[lo]);
            temp2 = isVowel(s[hi]);
            if (temp1 && temp2) {
                swap(s[lo], s[hi]);
                ++lo;
                --hi;
            } else if (temp1) {
                --hi;
            } else if (temp2) {
                ++lo;
            } else {
                ++lo;
                --hi;
            }
        }
        return s;
    }
};