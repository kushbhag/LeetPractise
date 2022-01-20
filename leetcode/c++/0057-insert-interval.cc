// https://leetcode.com/problems/insert-interval/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        bool inserted = false;

        for (vector<int> &curr: intervals) {
            if (inserted || curr[1] < newInterval[0]) {
                ret.push_back(curr);
            } else if (newInterval[1] < curr[0]) {
                ret.push_back(newInterval);
                ret.push_back(curr);
                inserted = true;
            } else {
                newInterval[0] = min(curr[0], newInterval[0]);
                newInterval[1] = max(curr[1], newInterval[1]);
            }
        }
        if (!inserted) ret.push_back(newInterval);
        return ret;
    }
};