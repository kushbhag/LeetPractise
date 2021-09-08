// https://leetcode.com/problems/palindromic-substrings/
// Medium

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), count = 0;
        vector<vector<bool>> v (len+1, vector<bool> (len, false));

        int hi;
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i+j < len; ++i) {
                hi = i+j;
                if (s[i] == s[hi] && (j <= 1 || v[i+1][hi-1])) {
                    //cout << i << " " << hi << endl;
                    ++count;
                    v[i][hi] = true;
                }
            }
        }
        return count;
    }
};

// O(n^2) and O(1) space
class Solution1 {
public:
    int countSubstrings(string s) {
        int lo = 0, hi = 0, count = 0;
        int len = s.length();
        for (int i = 0; i < len-1; ++i) {
            lo = i;
            hi = i;
            while (lo >= 0 && hi < len) {
                if (s[lo] == s[hi]) {
                    ++count;
                } else break;
                --lo;
                ++hi;
            }
            lo = i;
            hi = i+1;
            while (lo >= 0 && hi < len) {
                if (s[lo] == s[hi]) {
                    ++count;
                } else break;
                --lo;
                ++hi;
            }
        }
        return count+1;
    }
};