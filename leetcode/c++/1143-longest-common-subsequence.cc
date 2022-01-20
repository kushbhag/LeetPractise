// https://leetcode.com/problems/longest-common-subsequence/
// Medium

#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    int len1, len2;
public:
    int longestCommonSubsequence(string text1, string text2) {
        len1 = text1.length();
        len2 = text2.length();
        vector<vector<int>> v (len1 + 1, vector<int> (len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    v[i][j] = v[i-1][j-1] + 1;
                } else {
                    v[i][j] = max (v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[len1][len2];

    }
};