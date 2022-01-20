// https://leetcode.com/problems/top-k-frequent-elements/
// Medium

#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int &n: nums) ++m[n];
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;
        for (pair<int, int> p: m) {
            if (pq.size() == k && p.second > pq.top().first) {
                pq.pop();
                pq.push({p.second, p.first});
            } else if (pq.size() < k) {
                pq.push({p.second, p.first});
            }
        }
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};