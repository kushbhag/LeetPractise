// https://leetcode.com/problems/longest-palindromic-substring/
// Medium

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length(), maxSoFar = 0, maxLength = 0;
        vector<vector<bool>> v (size, vector<bool> (size, false));
        for (int i = 0; i < size; ++i) {
            v[i][i] = true;
        }
        for (int i = 1; i < size; ++i) {
            v[i][i-1] = true;
        }
        for (int j = 1; j < size; ++j) {
            for (int i = 0; i + j < size; ++i) {
                if (s[i] == s[i+j] && v[i+1][i+j-1]) {
                    v[i][i+j] = true;
                    if (maxLength < j) {
                        maxSoFar = i;
                        maxLength = j;
                    }
                }
            }
        }
        return s.substr(maxSoFar, maxLength + 1);
    }
};