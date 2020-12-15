// https://leetcode.com/problems/combination-sum/
// Medium
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> v (target+1, vector<vector<int>> (0));
        v[0] = vector<vector<int>> (1, vector<int> (0));
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        for (int i = 1; i <= target; ++i) {
            unordered_set<int> s;
            for (int j = 0; j < size; ++j) {
                if (s.find(candidates[j]) != s.end()) continue;
                if (candidates[j] > i) break;
                else if (v[i - candidates[j]].size() > 0) {
                    for (vector<int> temp: v[i - candidates[j]]) {
                        for (int n: temp) {
                            s.insert(n);
                        }
                        temp.push_back(candidates[j]);
                        v[i].push_back(temp);
                    }
                }
            }
        }
        return v[target];
    }
};