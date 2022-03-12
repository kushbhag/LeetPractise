# https://leetcode.com/problems/course-schedule/
# Medium

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
