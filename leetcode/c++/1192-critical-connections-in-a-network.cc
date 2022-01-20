// https://leetcode.com/problems/critical-connections-in-a-network/
// Hard

#include<vector>

using namespace std;

class Solution {
    vector<vector<int>> ret;
    vector<vector<int>> al;
    vector<int> discovery;
    vector<int> low;
    int index = 0;

    void lowestId(int curr, int prev) {
        discovery[curr] = low[curr] = index++; // Set discovery and low time to same
        for (int next: al[curr]) {  // Go through all adjacencies
            if (discovery[next] == -1) {    // If adjacent node is not visited, then visit it
                lowestId(next, curr);
                low[curr] = min(low[curr], low[next]);  // Set your low to the min of your low or it's
            } else if (next != prev) {  // Assuming you are not the previosu node
                low[curr] = min(low[curr], discovery[next]); // Set your low to min of yourself or discovery of next
            }
            if (discovery[curr] < low[next]) {  // If your discovery time is less than the low of next, then there was
                                                //   no loop to circle back around, hence it is a bridge
                ret.push_back({curr, next});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        al = vector<vector<int>> (n);
        discovery = vector<int> (n, -1);
        low = vector<int> (n, -1);
        for (vector<int> &v: connections) { // Creating adjacency list
            al[v[0]].push_back(v[1]);
            al[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < n; ++i) { // Performing DFS on each node (in case of multiple components)
            if (discovery[i] == -1) lowestId(i, -1);
        }
        return ret;
    }
};