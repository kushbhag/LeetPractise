// https://leetcode.com/problems/interleaving-string/
// Medium
// June 2nd, 2021 Coding Challenge

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3)  return false;
        vector<vector<bool>> v (len1+1, vector<bool> (len2+1, false));
        
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i == 0 && j == 0) {
                    v[i][j] = true;
                } else if (i == 0) {
                    v[i][j] = s3[i+j-1] == s2[j-1] && v[i][j-1];
                } else if (j == 0) {
                    v[i][j] = s3[i+j-1] == s1[i-1] && v[i-1][j];
                } else {
                    v[i][j] = (s3[i+j-1] == s1[i-1] && v[i-1][j]) || (s3[i+j-1] == s2[j-1] && v[i][j-1]);
                }
            }
        }
        
        return v[len1][len2];
    }
};