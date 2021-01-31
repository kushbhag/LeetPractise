// https://leetcode.com/problems/number-of-islands/
// Medium

#include<vector>

using namespace std;

class Solution {
    int width;
    int height;
    void markVisited(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= height || j < 0 || j >= width || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        markVisited(grid, i+1, j);
        markVisited(grid, i-1,j);
        markVisited(grid, i, j+1);
        markVisited(grid, i, j-1);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        width = grid[0].size();
        height = grid.size();
        int islands = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    markVisited(grid, i, j);
                }
            }
        }
        return islands;
    }
};