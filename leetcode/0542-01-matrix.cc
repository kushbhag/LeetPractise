// https://leetcode.com/problems/01-matrix/
// Medium
// July 29th, 2021

#include<vector>
#include<queue>
using namespace std;

class Solution {
    const int highest = 10000;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> v = vector<vector<int>> (row, vector<int> (col, highest));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 0) q.push({i, j, 0});
            }
        }
        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            if (temp[2] < v[temp[0]][temp[1]]) {
                v[temp[0]][temp[1]] = temp[2];
                if (temp[0] > 0) {
                    q.push({temp[0]-1, temp[1], temp[2] + 1});
                }
                if (temp[1] > 0) {
                    q.push({temp[0], temp[1]-1, temp[2] + 1});
                }
                if (temp[0] < row-1) {
                    q.push({temp[0]+1, temp[1], temp[2] + 1});
                }
                if (temp[1] < col-1) {
                    q.push({temp[0], temp[1]+1, temp[2] + 1});
                }
            }
        }
        return v;
    }
};