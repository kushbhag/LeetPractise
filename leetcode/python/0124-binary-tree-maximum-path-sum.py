# https://leetcode.com/problems/binary-tree-maximum-path-sum/
# Hard

# Recursively call recurseMaxPathSum on both left and right subtrees, and max that to 0
# Keep track of the maxSoFar which is simply the max of itself and root.val + left + right
# In the recursive function, you return root.val + max(left, right) so that you
#   are only ever selecting one of the left or right subtrees
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSoFar = float("-inf")

        def recurseMaxPathSum(root: Optional[TreeNode]) -> int:
            nonlocal maxSoFar

            if not root:
                return 0
            left, right = max(recurseMaxPathSum(root.left), 0), max(recurseMaxPathSum(root.right), 0)
            maxSoFar = max(maxSoFar, root.val + left + right)
            return root.val + max(left, right)
    
        recurseMaxPathSum(root)
        return maxSoFar