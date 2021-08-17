// https://leetcode.com/problems/minimum-falling-path-sum/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> v = vector<vector<int>> (rows, vector<int> (cols, INT_MAX));
        for (int i = 0; i < cols; ++i) v[0][i] = matrix[0][i];

        for (int i = 0; i < rows-1; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j > 0) {
                    v[i+1][j-1] = min(v[i+1][j-1], v[i][j] + matrix[i+1][j-1]);
                }
                if (j < cols-1) {
                    v[i+1][j+1] = min(v[i+1][j+1], v[i][j] + matrix[i+1][j+1]);
                }
                v[i+1][j] = min(v[i+1][j], v[i][j] + matrix[i+1][j]);
            }
        }
        int minSum = INT_MAX;
        for (int i = 0; i < cols; ++i) minSum = min(minSum, v[rows-1][i]);
        return minSum;
    }
};