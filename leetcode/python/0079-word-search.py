# https://leetcode.com/problems/word-search/
# Medium

# Create a recursive function to check if the word is on the path using DFS
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        def rec(i: int, j: int, word: str) -> bool:
            nonlocal board
            if i < 0 or j < 0 or i >= m or j >= n or board[i][j] != word[0]:
                return False
            
            if len(word) == 1:
                return True
            
            c, board[i][j], word = board[i][j], '.', word[1:]
            e = rec(i+1, j, word) or rec(i-1, j, word) or rec(i, j+1, word) or rec(i, j-1, word)
            board[i][j] = c
            return e
            
        
        for i in range(m):
            for j in range(n):
                if rec(i, j, word):
                    return True
        return False
                