// https://leetcode.com/problems/unique-paths/
// Medium

/*
    DISCLAIMER: The answer is really simply just (n+m-2) C n 
        but I will be using a DP approach just to test my knowledge
*/
#include<vector>
using namespace std;


class Solution {
    int uniquePathsMemo(int m, int n, vector<vector<int>>& memo) {
        if (m == 1) return 1;
        if (n == 1) return 1;
        if (memo[n][m]) {
            return memo[n][m];
        }
        memo[n][m] = uniquePathsMemo(m-1, n, memo) + uniquePathsMemo(m, n-1, memo);
        return memo[n][m];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v (n+1, vector<int> (m+1, 0));
        return uniquePathsMemo(m, n, v);
    }
};