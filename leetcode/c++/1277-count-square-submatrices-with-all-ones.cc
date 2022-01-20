// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Medium
// Mock

#include<vector>

using namespace std;

class Solution {
    vector<vector<int>> mem;
    int width, height;
    int count = 0;
    int sizeOfSquare(vector<vector<int>>& matrix, int i, int j) {
        if (mem[i][j]) return mem[i][j];
        if (i+1 >= height || j+1 >= width) {
            ++count;
            mem[i][j] = 1;
            return 1;
        }
        int size = 1;
        if (matrix[i+1][j] == 1 && matrix[i+1][j+1] == 1 && matrix[i][j+1] == 1) {
            size = 1 + min(sizeOfSquare(matrix, i+1, j), min(sizeOfSquare(matrix, i, j+1), sizeOfSquare(matrix, i+1, j+1)));
            count += size;
        } else {
            ++count;
        }
        mem[i][j] = size;
        return size;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        width = matrix[0].size();
        height = matrix.size();
        mem = vector<vector<int>> (height, vector<int> (width, 0));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 1 && !mem[i][j]) {
                    sizeOfSquare(matrix, i, j);
                }
            }
        }
        return count;
    }
};