// https://leetcode.com/problems/two-city-scheduling/
// Medium
// Mock

#include<vector>
#include<queue>

using namespace std;


// Using sorting by saving
class Solution1 {
    static bool myFunction(vector<int> v1, vector<int> v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n =  costs.size() / 2;
        int sum = 0;
        sort(costs.begin(), costs.end(), myFunction);
        for (int i = 0; i < n; ++i) {
            sum += costs[i][0] + costs[i+n][1];
        }
        return sum;
    }
};;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, int>> pqa;
        priority_queue<pair<int, int>> pqb;
        int total = 0;
        pair<int, int> temp;
        int size = costs.size(), a = size/2, b = size/2;
        for (int i = 0; i < size; ++i) {
            if (a == 0) {
                if (costs[i][0] < costs[i][1]) {
                    temp = pqa.top();
                    if (abs(temp.first) > abs(costs[i][0] - costs[i][1])) {
                        pqb.push(pair<int, int> {costs[i][1]-costs[i][0], i});
                        total += costs[i][1];
                    } else {
                        pqa.pop();
                        pqa.push(pair<int, int> {costs[i][0]-costs[i][1], i});
                        total += costs[i][0];
                        pqb.push(pair<int, int> {costs[temp.second][1]-costs[temp.second][0], temp.second});
                        total -= costs[temp.second][0];
                        total += costs[temp.second][1];
                    }
                } else {
                    pqb.push(pair<int, int> {costs[i][1]-costs[i][0], i});
                    total += costs[i][1];
                }
                --b;
            } else if (b == 0) {
                if (costs[i][0] > costs[i][1]) {
                    temp = pqb.top();
                    if (abs(temp.first) > abs(costs[i][1] - costs[i][0])) {
                        pqa.push(pair<int, int> {costs[i][0]-costs[i][1], i});
                        total += costs[i][0];
                    } else {
                        pqb.pop();
                        pqb.push(pair<int, int> {costs[i][1]-costs[i][0], i});
                        total += costs[i][1];
                        pqa.push(pair<int, int> {costs[temp.second][0]-costs[temp.second][1], temp.second});
                        total -= costs[temp.second][1];
                        total += costs[temp.second][0];
                    }
                } else {
                    pqa.push(pair<int, int> {costs[i][0]-costs[i][1], i});
                    total += costs[i][0];
                }
                --a;
            } else {
                if (costs[i][0] < costs[i][1]) {
                    pqa.push(pair<int, int> {costs[i][0]-costs[i][1], i});
                    total += costs[i][0];
                    --a;
                } else {
                    pqb.push(pair<int, int> {costs[i][1]-costs[i][0], i});
                    total += costs[i][1];
                    --b;
                }
            }
        }
        return total;
    }
};