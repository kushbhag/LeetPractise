// https://leetcode.com/problems/out-of-boundary-paths/
// Medium

#include<vector>

using namespace std;

class Solution {
    const int modulo = 1000000007;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<long>> v = vector<vector<long>> (m+2, vector<long>(n+2, 0));
        v[startRow+1][startColumn+1] = 1;
        
        int out = 0;
        
        for (int x = 0; x < maxMove; ++x) {
            vector<vector<long>> temp = vector<vector<long>> (m+2, vector<long>(n+2, 0));
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    int t = 0;
                    if (i == 1) ++t;
                    if (j == 1) ++t;
                    if (i == m) ++t;
                    if (j == n) ++t;
                    temp[i][j] = (v[i-1][j] + v[i+1][j]) % modulo;
                    temp[i][j] = (temp[i][j] + v[i][j+1] + v[i][j-1]) % modulo;
                    out = (out + (v[i][j] * t)) % modulo;
                }
            }
            v = temp;
        }
        return out;
    }
};
