# https://leetcode.com/problems/number-of-islands/
# Medium

# Simple DFS
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        moves = [[0,1],[1,0],[-1,0],[0,-1]]
        
        def removeOnes(i: int, j: int):
            nonlocal grid

            if i >= 0 and j >= 0 and j < n and i < m and grid[i][j] == '1':
                grid[i][j] = '0'
                for move in moves:
                    removeOnes(i+move[0], j+move[1])
                    
        
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    removeOnes(i, j)
        return count