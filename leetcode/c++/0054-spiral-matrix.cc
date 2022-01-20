// https://leetcode.com/problems/spiral-matrix/
// Medium

#include<vector>
using namespace std;

class Solution {
vector<vector<bool>> checked;
    vector<int> ret;
    int rows, cols;
    enum Direction {left, right, top, bottom};
    Direction direction = right;
    pair<int, int> d = {0, 1};

    void changeDirection() {
        if (direction == right) {
            direction = bottom;
            d = {1, 0};
        } else if (direction == bottom) {
            direction = left;
            d = {0, -1};
        } else if (direction == left) {
            direction = top;
            d = {-1, 0};
        } else {
            direction = right;
            d = {0, 1};
        }
    }

    bool spiralOrderRec(vector<vector<int>>& matrix, int i, int j) {
        if (i >= rows || j >= cols || i < 0 || j < 0 || checked[i][j]) return false;
        ret.push_back(matrix[i][j]);
        checked[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            if (spiralOrderRec(matrix, i+d.first, j+d.second)) {
                return true;
            }
            changeDirection();
        }
        return true;
    }
    
    

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        checked = vector<vector<bool>> (rows, vector<bool> (cols, false));
        spiralOrderRec(matrix, 0, 0);
        return ret;
    }
};