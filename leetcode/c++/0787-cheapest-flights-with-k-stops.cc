// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Medium

#include<vector>
#include<unordered_map>
using namespace std;

// DFS
// Time limit exceeded
class Solution {
    vector<vector<pair<int, int>>> f;
    vector<bool> checked;
    int globalMin = INT_MAX;
    void findCheapestPriceRec(int src, int dst, int k, int sum) {
        if (k < 0 || checked[src] || sum > globalMin) return;
        if (src == dst) {
            globalMin = min(sum, globalMin);
            return;
        }
        checked[src] = true;
        for (pair<int, int> flight: f[src]) {
            findCheapestPriceRec(flight.first, dst, k-1, sum + flight.second);
        }
        checked[src] = false;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        f = vector<vector<pair<int, int>>> (n);
        checked = vector<bool> (n, false);
        for (vector<int> v: flights) {
            f[v[0]].push_back({v[1], v[2]});
        }
        findCheapestPriceRec(src, dst, k+1, 0);

        return globalMin == INT_MAX ? -1 : globalMin;
    }
};

// Bellman Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp = vector<vector<int>> (k+2, vector<int> (n, INT_MAX));

        for (int i = 1; i <= k+1; ++i) {
            dp[i-1][src] = 0;
            for (vector<int> v: flights) {
                if (dp[i-1][v[0]] != INT_MAX)
                    dp[i][v[1]] = min(dp[i][v[1]], dp[i-1][v[0]] + v[2]);
            }
        }
        return dp[k+1][dst] == INT_MAX ? -1 : dp[k+1][dst];
    }
};
