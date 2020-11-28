#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor,
 and you can either start from the step with index 0, or the step with index 1.
*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int finalCost = 0;

        for (int i = 0; i < cost.size();){
            cout << "i : "<< i << endl;
            if (cost.size() == 2 + i){
                return finalCost;
            } else if (cost.size()-1 == i){
                return finalCost;
            } else if (i == 0){
                if (cost.size() %2 == 0){
                    if (cost[i] + cost[i+2] <= cost[i+1]){
                        finalCost = finalCost + cost[i] + cost[i+2];
                        i = i + 2;
                    } else {
                        finalCost = finalCost+ cost[i+1];
                        ++i;
                    }
                } else {
                    if (cost[i] + cost[i+2] < cost[i+1]){
                        finalCost = finalCost + cost[i] + cost[i+2];
                        i = i + 2;
                    } else {
                        finalCost = finalCost+ cost[i+1];
                        ++i;
                    }
                }
                continue;
            }
            if (cost.size() % 2 == 0){
                if (cost[i] <= cost[i+1]){
                    finalCost += cost[i];
                    ++i;
                } else {
                    finalCost += cost[i+1];
                    i += 2;
                }
            } else {
                if (cost[i] < cost[i+1]){
                    finalCost += cost[i];
                    ++i;
                } else {
                    finalCost += cost[i+1];
                    i += 2;
                }
            }
        }
        return finalCost;
    }
};

int main(){
    vector<int> step = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution x;
    cout << x.minCostClimbingStairs(step) << endl;
}