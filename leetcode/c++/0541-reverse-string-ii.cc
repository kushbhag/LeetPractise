// https://leetcode.com/problems/reverse-string-ii/
// Easy

#include<string>

using namespace std;

class Solution {
public:
     string reverseStr(string s, int k) {
        int len = s.length();
        int lo,hi;
        char temp;
        for (int i = 0; i < len; i+=2*k) {
            lo = i;
            hi = i+k-1;
            //cout << i << ' ' << lo << ' ' << hi << endl;
            while(lo <= hi) {
                if (hi >= len) {
                    --hi;
                } else {
                    swap(s[lo], s[hi]);
                    ++lo;
                    --hi;
                }
            }
        }
        return s;
    }
};