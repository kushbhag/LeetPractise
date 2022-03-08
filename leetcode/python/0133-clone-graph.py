# https://leetcode.com/problems/clone-graph/
# Medium

# A simple DFS with a visited set
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        self.visited = {}
        
        def recCloneGraph(node: 'Node') -> 'Node':
            if node.val in self.visited:
                return self.visited[node.val]
            
            newNode = Node(node.val)
            self.visited[node.val] = newNode
            newNode.neighbors = [recCloneGraph(n) for n in node.neighbors]

            return newNode

        return recCloneGraph(node)