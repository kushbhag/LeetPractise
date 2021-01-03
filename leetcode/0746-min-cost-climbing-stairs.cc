// https://leetcode.com/problems/min-cost-climbing-stairs/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        for (int i = 2; i < size; ++i) {
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }
        return min(cost[size-1], cost[size-2]);
    }
};