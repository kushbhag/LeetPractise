#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
https://leetcode.com/problems/network-delay-time/discuss/109982/C%2B%2B-Bellman-Ford
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
*/

class Solution {
    bool check (unordered_map<int, int> m, int N){
        for (int i = 1; i <= N; i ++){
            if (m[i] < 1) return false;
        }
        return true;
    }
    int networkDelayTimeMap(vector<vector<int>>& times, int N, int K, unordered_map<int, int> m) {
        int res = 0;
        if (check(m, N)) return res;
        for (int i = 0; i < times.size(); i ++){
            if(times[i][0] == K){
                int tempRes = res + times[i][2];
                m[times[i][1]]++;
                tempRes = tempRes + this->networkDelayTimeMap(times, N, times[i][1], m);
                res = max(tempRes, res);
            }
        }
        return res;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map <int, int> m;
        int res = this->networkDelayTimeMap(times, N, K, m);
        if (this->check(m, N) == false) return -1;
        return res;
    }
};