// https://leetcode.com/problems/island-perimeter/
// Easy
// Mock

#include<vector>

using namespace std;

class Solution {
    int width, height;
    int count = 0;
    int findPerimeter(vector<vector<int>>& grid, int col, int row, vector<vector<bool>>& mem) {
        if (col >= height || col < 0 || row >= width || row < 0 || grid[col][row] == 0) return 0;
        if (mem[col][row] == true) return 1;
        
        mem[col][row] = true;
        int temp = findPerimeter(grid, col-1, row, mem) + findPerimeter(grid, col+1, row, mem) +
                   findPerimeter(grid, col, row-1, mem) + findPerimeter(grid, col, row+1, mem);
        count += 4 - temp;
        return 1;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        vector<vector<bool>> mem (height, vector<bool> (width, false));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 1) {
                    findPerimeter(grid, i, j, mem);
                    return count;
                }
            }
        }
        return count;
    }
};