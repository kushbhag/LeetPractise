// https://leetcode.com/problems/course-schedule/
// Medium

#include<vector>

using namespace std;

class Solution {
     vector<vector<int>> mem;
    vector<bool> v;
    bool canFinishDFS(int numCourses, int currCourse) {
        if (mem[currCourse].empty()) {
            return true;
        } else if (v[currCourse]) return false;

        v[currCourse] = true;
        for (int &n: mem[currCourse]) {
            if (!canFinishDFS(numCourses, n)) return false;
        }
        mem[currCourse].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        mem = vector<vector<int>> (numCourses, vector<int> ());
        for (vector<int> &v: prerequisites) {
            mem[v[0]].push_back(v[1]);
        }
        v = vector<bool> (numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!v[i] && !canFinishDFS(numCourses, i)) return false;
        }
        return true;
    }
};