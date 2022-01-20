// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Hard

#include<vector>

using namespace std;

class Solution {
    int width, height;
    int longestPath(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int prev) {
        if (i < 0 || i >= height || j < 0 || j >= width || matrix[i][j] <= prev) return 0;
        if (visited[i][j] > 0) return visited[i][j];
        visited[i][j] = max(longestPath(matrix, visited, i+1, j, matrix[i][j]),
                            max(longestPath(matrix, visited, i, j+1, matrix[i][j]),
                                max(longestPath(matrix, visited, i-1, j, matrix[i][j]),
                                    longestPath(matrix, visited, i, j-1, matrix[i][j])))) + 1;
        return visited[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        width = matrix[0].size();
        height = matrix.size();
        vector<vector<int>> visited (height, vector<int> (width, 0));
        int maxSoFar = 1;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                maxSoFar = max(maxSoFar, longestPath(matrix, visited, i, j, INT_MIN));
            }
        }
        return maxSoFar;
    }
};