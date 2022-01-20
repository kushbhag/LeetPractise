// https://leetcode.com/problems/game-of-life/
// Medium

#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size(), colSize = board[0].size();
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                int count = board[i][j] == 1 ? -1 : 0;
                for (int r = max(i-1, 0); r <= min(i+1, rowSize-1); ++r) {
                    for (int c = max(j-1, 0); c <= min(j+1, colSize-1); ++c) {
                        count = board[r][c] == 1 || board[r][c] == -1 ? count + 1 : count;
                    }
                }
                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = -1;
                } else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};