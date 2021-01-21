// https://leetcode.com/problems/flood-fill/
// Easy
// Mock

#include<vector>

using namespace std;

class Solution {
    int width, height, oldColor;
    void floodFillRec(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& mem) {
        if (sr >= height || sr < 0 || sc >= width || sc < 0 || mem[sr][sc] || image[sr][sc] == newColor) return;
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            floodFillRec(image, sr+1, sc, newColor, mem);
            floodFillRec(image, sr-1, sc, newColor, mem);
            floodFillRec(image, sr, sc+1, newColor, mem);
            floodFillRec(image, sr, sc-1, newColor, mem);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        width = image[0].size();
        height = image.size();
        oldColor = image[sr][sc];
        vector<vector<bool>> mem (height, vector<bool> (width, false));
        floodFillRec(image, sr, sc, newColor, mem);
        return image;
    }
};