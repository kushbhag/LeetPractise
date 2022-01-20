// https://leetcode.com/problems/set-matrix-zeroes/
// Medium
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    int rowSize, colSize;
    void setRowZero(vector<vector<int>>& matrix, int row) {
        for (int i = 0; i < colSize; ++i) {
            matrix[row][i] = 0;
        }
    }
    void setColZero(vector<vector<int>>& matrix, int col) {
        for (int i = 0; i < rowSize; ++i) {
            matrix[i][col] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        rowSize = matrix.size();
        colSize = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int i = 0; i < rowSize; ++i) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }
        for (int i = 0; i < colSize; ++i) {
            if (matrix[0][i] == 0) {
                rowZero = true;
                break;
            }
        }
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < colSize; ++i) {
            // cout << matrix[0][i] << ' ';
            if (matrix[0][i] == 0) setColZero(matrix, i);
        }
        // cout << endl;
        for (int i = 1; i < rowSize; ++i) {
            // cout << matrix[i][0] << ' ';
            if (matrix[i][0] == 0) setRowZero(matrix, i);
        }
        if (rowZero) {
            setRowZero(matrix, 0);
        }
        if (colZero) {
            setColZero(matrix, 0);
        }
    }
};