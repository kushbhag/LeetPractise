# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
# Medium

# Key is to find preorder[0] in inorder. Then whatever index it exists on inorder, the left
#   of that is the left of the tree, and the right of that is the right of the tree
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        ret = TreeNode(preorder[0])
        
        i = inorder.index(preorder[0])
        if i > 0:
            ret.left = self.buildTree(preorder[1:i+1], inorder[:i])
        if i < len(inorder)-1:
            ret.right = self.buildTree(preorder[i+1:], inorder[i+1:])
        return ret