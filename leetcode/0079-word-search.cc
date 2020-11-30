// https://leetcode.com/problems/word-search/
// Medium

#include<vector>
#include<string>
#include<utility>
#include<unordered_set>
using namespace std;

class Solution {
    int width;
    int height;
    bool isWord(vector<vector<char>>& board, string word, int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= this->width || j >= this->height || board[i][j] == '\0') {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }
        if (index + 1 >= word.size()) return true;
        
        char c = board[i][j];
        index ++;
        board[i][j] = '\0';
        if (isWord(board, word,i-1,j, index) || isWord(board, word, i+1, j, index) || 
            isWord(board, word,i,j-1, index) || isWord(board, word, i, j+1, index)) {
                return true;
        }
        index --;
        board[i][j] = c;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->width = board.size();
        this->height = board[0].size();      
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (isWord(board,word,i,j,0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main() {

}