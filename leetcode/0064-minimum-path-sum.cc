// https://leetcode.com/problems/minimum-path-sum/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        vector<vector<int>> v (height, vector<int> (width, 0));
        int temp = 0;
        for (int i = 0; i < height; ++i) {
            temp += grid[i][0];
            v[i][0] = temp;
        }
        temp = 0;
        for (int i = 0; i < width; ++i) {
            temp += grid[0][i];
            v[0][i] = temp;
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                v[i][j] = min(v[i-1][j], v[i][j-1]) + grid[i][j];
            }
        }

        return v[height-1][width-1];
    }
};