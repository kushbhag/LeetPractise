# https://leetcode.com/problems/binary-tree-level-order-traversal/
# Medium

from collections import deque

# Better solution is to use BFS
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        ret = []
        q = deque([root])
        while len(q) > 0:
            l = len(q)
            ret.append([])

            for _ in range(l):
                node = q.popleft()
                ret[-1].append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ret

# Another solution is to use DFS where you keep track of the level
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ret = []
        
        def levelOrderRec(root: Optional[TreeNode], level: int):
            nonlocal ret
            if not root:
                return
            
            if level >= len(ret):
                ret.append([])
            ret[level].append(root.val)
            levelOrderRec(root.left, level+1)
            levelOrderRec(root.right, level+1)

        levelOrderRec(root, 0)
        return ret
