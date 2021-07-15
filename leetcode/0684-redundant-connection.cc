// https://leetcode.com/problems/redundant-connection/
// Medium
// June 25th, 2021 Challenge

#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for (vector<int> v: edges) {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }
        for (int i = edges.size()-1; i >= 0; --i) {
            unordered_set<int> s;
            vector<int> stack;
            s.insert(edges[i][0]);
            for (int x: m[edges[i][0]]) {
                if (x != edges[i][1]) {
                    s.insert(x);
                    stack.push_back(x);
                }
            }
            while (!stack.empty()) {
                int last = stack.back();
                if (last == edges[i][1]) return edges[i];
                stack.pop_back();
                for (int x: m[last]) {
                    if (s.find(x) == s.end()) {
                        s.insert(x);
                        stack.push_back(x);
                    }
                }
            }
        }
        return {0, 0};
    }
};

class Solution1 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for (vector<int> v: edges) {
            if (m[v[0]].find(v[1]) != m[v[0]].end() || 
                m[v[1]].find(v[0]) != m[v[1]].end()) return v;
            unordered_set<int> s;
            vector<int> stack;
            stack.push_back(v[0]);
            while (!stack.empty()) {
                int last = stack.back();
                stack.pop_back();
                m[last].insert(v[1]);
                for (int x: m[last]) {
                    if (s.find(x) == s.end()) {
                        s.insert(x);
                        stack.push_back(last);
                    }
                }
            }
            stack.push_back(v[1]);
            while (!stack.empty()) {
                int last = stack.back();
                stack.pop_back();
                m[last].insert(v[0]);
                for (int x: m[last]) {
                    if (s.find(x) == s.end()) {
                        s.insert(x);
                        stack.push_back(last);
                    }
                }
            }
        }
        return {0,0};
    }
};