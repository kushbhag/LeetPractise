// https://leetcode.com/problems/max-area-of-island/
// Medium
// June 1st, Leetcode Challenge

#include<vector>

using namespace std;

class Solution {
    int maxArea = 0;
    int width, height;
    void explore(int i, int j, vector<vector<int>>& grid, int& current) {
        if (i >= height || j >= width || i < 0 || j < 0 || grid[i][j] == 0) {
            return;
        }
        ++current;
        grid[i][j] = 0;
        explore(i-1, j, grid, current);
        explore(i+1, j, grid, current);
        explore(i, j-1, grid, current);
        explore(i, j+1, grid, current);
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int current = 0;
                explore(i, j, grid, current);
                maxArea = max(maxArea, current);
            }
        }
        return maxArea;
    }
};