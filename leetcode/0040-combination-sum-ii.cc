// https://leetcode.com/problems/combination-sum-ii/
// Medium
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
    int size;
    void combinationSumRec(vector<int>& candidates, int sum, int start, vector<int> temp, vector<vector<int>>& ret) {
        if (sum < 0) return;
        else if (sum == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i < size; ++i) {
            if (sum - candidates[i] < 0) break;
            temp.push_back(candidates[i]);
            combinationSumRec(candidates, sum - candidates[i], i+1, temp, ret);
            while (i+1 < size && candidates[i] == candidates[i+1]) ++i;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        size = candidates.size();
        combinationSumRec(candidates, target, 0, vector<int> (), ret);
        return ret;
    }
};