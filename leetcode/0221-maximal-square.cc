// https://leetcode.com/problems/maximal-square/
// Medium

#include<vector>

using namespace std;

class Solution {
    int rowSize, colSize;
    vector<vector<int>> mem;
    int checkCorner(int row, int col, vector<vector<char>>& v) {
        if (row-1 < 0 || col-1 < 0) return 1;
        if (v[row-1][col-1] == '1' && v[row-1][col] == '1' && v[row][col-1] == '1') {
            return min(mem[row-1][col-1], min(mem[row-1][col], mem[row][col-1])) + 1;
        }
        return 1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        rowSize = matrix.size();
        colSize = matrix[0].size();
        mem = vector<vector<int>> (rowSize, vector<int> (colSize, 0));
        int maxSoFar = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (matrix[i][j] != '0') {
                    mem[i][j] = checkCorner(i, j, matrix);
                    maxSoFar = mem[i][j] > maxSoFar ? mem[i][j] : maxSoFar;
                }
            }
        }
        return maxSoFar * maxSoFar;
    }
};