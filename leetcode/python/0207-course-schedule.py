# https://leetcode.com/problems/course-schedule/
# Medium
# TWO Solutions

# BFS that counts the indegree for each vertex
# Start only on the nodes with indegree == 0 (leaf nodes)
# Then parse through it's neighbors, reducing the indegree by 1
# Then continuously add the neighboring nodes only if the indegree of them is 0
#      We do this so we don't have duplicates nodes in the queue
# If ever the indegree of the neighbor is less than 0 there is a cycle (return False)
# Once the BFS is complete, we `return not any(g)`
# Any checks if there is anything in the iterator that is True
# So if all elements are zero, not any() will return True
# We can technically just return True over here, but it will fail when we have self cycle [[0,1], [1, 1]]
from collections import deque
class Solution:
    def canFinish(self, n: int, prereq: List[List[int]]) -> bool:
        graph = [[] for _ in range(n)]
        g = [0] * n
        
        for f, s in prereq:
            graph[f].append(s)
            g[s] += 1
        
        q = deque([p for p in range(n) if g[p] == 0])
        while q:
            p = q.popleft()
            for neighbor in graph[p]:
                g[neighbor] -= 1
                if g[neighbor] == 0:
                    q.append(neighbor)
                elif g[neighbor] < 0:
                    return False
        return not any(g)
                


# It is NOT just a simple DFS
# You also need to check if you have fully parsed the course you are currently at before or not
# This means checking if neighbor >= orig, because we already know that anything less than
#   orig has been checked completely
class Solution:
    def canFinish(self, numCourses: int, prereq: List[List[int]]) -> bool:
        adj = [set() for i in range(numCourses)]
        for l in prereq:
            adj[l[0]].add(l[1])
        
        visited = [False] * numCourses
        def dfs(course: int, orig: int) -> bool:
            nonlocal visited
            if visited[course]:
                return False
            
            visited[course] = True
            for neighbor in adj[course]:
                if neighbor >= orig:
                    if not dfs(neighbor, orig):
                        return False
            visited[course] = False
            return True
            
        for i in range(numCourses):
            if not dfs(i, i):
                return False
        return True
