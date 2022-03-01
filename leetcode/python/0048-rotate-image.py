# https://leetcode.com/problems/rotate-image/
# Medium

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        w = -(len(matrix) // -2)
        l = len(matrix) // 2
        for i in range(w):
            for j in range(l):
                matrix[i][j], matrix[j][len(matrix)-i-1] = matrix[j][len(matrix)-i-1], matrix[i][j]
                matrix[i][j], matrix[len(matrix)-i-1][len(matrix)-j-1] = matrix[len(matrix)-i-1][len(matrix)-j-1], matrix[i][j]
                matrix[i][j], matrix[len(matrix)-j-1][i] = matrix[len(matrix)-j-1][i], matrix[i][j]
