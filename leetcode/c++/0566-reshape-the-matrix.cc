// https://leetcode.com/problems/reshape-the-matrix/
// Easy
// July 5th, 2021 Challenge

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(), cols = mat[0].size();
        if (r * c != rows * cols) return mat;

        vector<vector<int>> v (r, vector<int> (0));
        int index = 0;
        int size = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (size == c) {
                    ++index;
                    size = 0;
                }
                v[index].push_back(mat[i][j]);
                ++size;
            }
        }
        return v;
    }
};