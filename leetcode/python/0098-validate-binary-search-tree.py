# https://leetcode.com/problems/validate-binary-search-tree
# Medium

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Simple solution is to use an inOrder traversal and check to see if the last element
#   is smaller than the current element
# Key is to use O(1) extra space by only keeping track of prev
class Solution:
    def __init__(self):
        self.last = float("-inf")
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        if not self.isValidBST(root.left):
            return False
        if root.val <= self.last:
            return False
        self.last = root.val
        return self.isValidBST(root.right)