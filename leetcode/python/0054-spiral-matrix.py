# https://leetcode.com/problems/spiral-matrix/
# Medium

# Have indexes that start with `top, left, bottom, right = 0, 0, len(matrix)-1, len(matrix[0])-1`
# Then increase top everytime you go right, decrease right when you go down and vice versa
# Your break condition is `top <= bottom and left <= right`
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top, left, bottom, right = 0, 0, len(matrix)-1, len(matrix[0])-1
        move = 0
        ret = []
        
        while top <= bottom and left <= right:
            if move == 0:
                for i in range(left, right+1):
                    ret.append(matrix[top][i])
                top += 1
            elif move == 1:
                for i in range(top, bottom+1):
                    ret.append(matrix[i][right])
                right -= 1
            elif move == 2:
                for i in range(right, left-1, -1):
                    ret.append(matrix[bottom][i])
                bottom -= 1
            elif move == 3:
                for i in range(bottom, top-1, -1):
                    ret.append(matrix[i][left])
                left += 1
            move = (move + 1)%4
        return ret
            
        return ret