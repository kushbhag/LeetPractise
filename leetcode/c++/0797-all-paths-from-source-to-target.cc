// https://leetcode.com/problems/all-paths-from-source-to-target/
// Medium

#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    //unordered_map<int, vector<vector<int>>> m;
    vector<vector<vector<int>>> m;
    vector<vector<int>> allPathsSourceTargetRec(vector<vector<int>>& graph, int start) {
        if (!m[start].empty()) {
            return m[start];
        }
        vector<vector<int>> ret;
        if (start == graph.size()-1) {
            ret.push_back({start});
            m[start] = ret;
            return ret;
        }
        for (int i = 0; i < graph[start].size(); ++i) {
            vector<vector<int>> v = allPathsSourceTargetRec(graph, graph[start][i]);
            for (auto x: v) {
                x.push_back(start);
                ret.push_back(x);
            }
        }
        m[start] = ret;
        return ret;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        m = vector<vector<vector<int>>> (graph.size());
        vector<vector<int>> ret = allPathsSourceTargetRec(graph, 0);
        for (vector<int>& v: ret) {
            reverse(v.begin(), v.end());
        }
        return ret;
    }
};