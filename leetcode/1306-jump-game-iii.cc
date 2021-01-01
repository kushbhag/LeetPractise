//https://leetcode.com/problems/jump-game-iii/

#include<vector>
#include<queue>
using namespace std;

// DFS
class Solution {
    int size;
    vector<bool> mem;
    vector<int> arr;
    bool canReachDFS(int start) {
        if (start < 0 || start >= size || mem[start]) return false;
        if (arr[start] == 0) return true;
        mem[start] = true;
        return canReachDFS(start+arr[start]) || canReachDFS(start-arr[start]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        size = arr.size();
        this->arr = arr;
        mem = vector<bool> (size, false);
        return canReachDFS(start);
    }
};

// BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        queue<int> q;
        vector<bool> v (size, false);
        v[start] = true;
        q.push(start);

        int curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (arr[curr] == 0) return true;
            if (curr + arr[curr] < size && !v[curr + arr[curr]]) {
                q.push(curr+arr[curr]);
                v[curr + arr[curr]] = true;
            }
            if (curr - arr[curr] >= 0 && !v[curr - arr[curr]]) {
                q.push(curr - arr[curr]);
                v[curr - arr[curr]] = true;
            }
        }
        return false;
    }
};