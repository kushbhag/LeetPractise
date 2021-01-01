// https://leetcode.com/problems/unique-paths-ii/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size(), width = obstacleGrid[0].size();
        vector<vector<int>> v (height, vector<int> (width, 0));
        for (int i = 1; i < width; ++i) {
            if (obstacleGrid[0][i] == 1) break;
            v[0][i] = 1;
        }
        for (int i = 1; i < height; ++i) {
            if (obstacleGrid[i][0] == 1) break;
            v[i][0] = 1;
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    v[i][j] = v[i-1][j] + v[i][j-1];
                }
            }
        }
        return v[height-1][width-1];
    }
};