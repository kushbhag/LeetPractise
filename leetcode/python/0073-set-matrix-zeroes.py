# https://leetcode.com/problems/set-matrix-zeroes/
# Medium

# Set the first row and column to zero's depending on everything else
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        fRow, fCol = False, False
        
        for i in range(len(matrix)):
            for j, n in enumerate(matrix[i]):
                if n == 0:
                    if i == 0:
                        fRow = True
                    if j == 0:
                        fCol = True
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(1, len(matrix[0])):
            if matrix[0][i] == 0:
                for j in range(len(matrix)):
                    matrix[j][i] = 0
            
        for i in range(1, len(matrix)):
            if matrix[i][0] == 0:
                matrix[i] = [0]*len(matrix[i])
                
        if fCol:
            for j in range(len(matrix)):
                matrix[j][0] = 0
        if fRow:
            matrix[0] = [0]*len(matrix[0])