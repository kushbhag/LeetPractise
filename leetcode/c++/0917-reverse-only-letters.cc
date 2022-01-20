// https://leetcode.com/problems/reverse-only-letters/
// Easy
// Mock

#include<string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int lo = 0, hi = S.length()-1;
        while (lo <= hi) {
            if (isalpha(S[lo]) && isalpha(S[hi])) {
                swap(S[lo], S[hi]);
                ++lo;
                --hi;
            } else if (isalpha(S[lo])) {
                --hi;
            } else if (isalpha(S[hi])) {
                ++lo;
            } else {
                --hi;
                ++lo;
            }
        }
        return S;
    }
};