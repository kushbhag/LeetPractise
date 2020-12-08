// https://leetcode.com/problems/number-of-islands/
// Medium

#include<vector>

using namespace std;

class Solution {
    int cols;
    int rows;
    void markIsland(vector<vector<char>>& grid, vector<vector<bool>>& memo, int i, int j) {
        memo[i][j] = true;
        if (i-1 >= 0 && !memo[i-1][j] && grid[i-1][j] == '1') {
            markIsland(grid, memo, i-1, j);
        }
        if (i+1 < rows && !memo[i-1][j] && grid[i+1][j] == '1') {
            markIsland(grid, memo, i+1, j);
        }
        if (j-1 >= 0 && !memo[i][j-1] && grid[i][j-1] == '1') {
            markIsland(grid, memo, i, j-1);
        }
        if (j+1 < cols && !memo[i][j+1] && grid[i][j+1] == '1') {
            markIsland(grid, memo, i, j+1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        cols = grid[0].size();
        rows = grid.size();
        int islands = 0;
        vector<vector<bool>> v (rows, vector<bool> (cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !v[i][j]) {
                    markIsland(grid, v, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }
};