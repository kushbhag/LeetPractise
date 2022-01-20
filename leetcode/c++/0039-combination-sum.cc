// https://leetcode.com/problems/combination-sum/
// Medium
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
    void combinationSumRec(vector<int>& candidates, int sum, int start, vector<int> temp, vector<vector<int>>& ret) {
        if (sum < 0) return;
        else if (sum == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (sum - candidates[i] < 0) break;
            temp.push_back(candidates[i]);
            combinationSumRec(candidates, sum - candidates[i], i, temp, ret);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        combinationSumRec(candidates, target, 0, vector<int> (), ret);
        return ret;
    }
};