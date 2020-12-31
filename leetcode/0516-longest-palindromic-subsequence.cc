// https://leetcode.com/problems/longest-palindromic-subsequence/
// Medium

#include<vector>
#include<string>

using namespace std;

class Solution {
    int longestPalindromeSubseqMemo(string s, vector<vector<int>>& v, int lo, int hi) {

    }
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        int lo=0, hi=1;
        vector<vector<int>> v (len, vector<int> (len, 0));
        for (int i=0; i<len;++i) {
            v[i][i] = 1;
        }
        int tempHi;
        while (hi-lo < len) {
            tempHi = hi;
            for (; hi<len; ++hi, ++lo) {
                if (s[lo] == s[hi]) {
                    v[lo][hi] = v[lo+1][hi-1] + 2;
                } else {
                    v[lo][hi] = max(v[lo+1][hi], v[lo][hi-1]);
                }
            }
            lo = 0;
            hi = tempHi+1;
        }
        return v[0][len-1];
    }
};