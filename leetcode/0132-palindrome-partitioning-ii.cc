// https://leetcode.com/problems/palindrome-partitioning-ii/
// Hard

#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    int len;
    vector<vector<bool>> v;
    int minSoFar = INT_MAX;
    int minCutRec(string s, int start, int count) {
        //cout << start;
        if (start >= len) {
            return count;
        }
        for (int i = start; i < len; ++i) {
            if (v[start][i]) {
                int temp = minCutRec(s, i+1, count+1);
                minSoFar = temp < minSoFar ? temp : minSoFar;
            }
        }
        return minSoFar;
    }
public:
    int minCut(string s) {
        len = s.length();
        v = vector<vector<bool>> (len, vector<bool> (len, false));
        vector<vector<int>> mem (len, vector<int> (len, 0));
        for (int i = 0; i < len; ++i) {
            mem[i][i] = i;
        }
        int hi;
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i+j < len; ++i) {
                hi = i+j;
                if (s[i] == s[hi] && (j <= 1 || v[i+1][hi-1])) {
                    if (i > 0) {
                        mem[i][hi] = mem[0][i-1]+1;
                    }
                }
            }
        }
    }
};