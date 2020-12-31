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