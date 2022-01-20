// https://leetcode.com/problems/sort-the-matrix-diagonally/
// Medium
// Mock

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();
        vector<vector<int>> diagonals;
        for (int i = 0; i < height; ++i) {
            diagonals.push_back(vector<int> ());
            for (int j = 0; i+j < height && j < width; ++j) {
                diagonals[i].push_back(mat[i+j][j]);
            }
        }
        for (int i = 1; i < width; ++i) {
            diagonals.push_back(vector<int> ());
            // cout << i + height-1 << endl;
            for (int j = 0; j < height && i+j < width; ++j) {
                //cout << j << ' ' << i+j << endl;
                diagonals[i+height-1].push_back(mat[j][i+j]);
            }
        }
        for (vector<int>&v: diagonals) {
            sort(v.begin(), v.end());
        }
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j+i < height && j < width; ++j) {
                mat[i+j][j] = diagonals[i][j];
            }
        }
        for (int i = 1; i < width; ++i) {
            for (int j = 0; j < height && i+j < width; ++j) {
                mat[j][i+j] = diagonals[i+height-1][j];
            }
        }
        return mat;
    }
};