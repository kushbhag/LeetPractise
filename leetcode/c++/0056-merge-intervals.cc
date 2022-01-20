// https://leetcode.com/problems/merge-intervals/
// Medium
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> currInterval = intervals[0];
        vector<vector<int>> ret;
        int size = intervals.size();
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] <= currInterval[1]) {
                currInterval[1] = max(currInterval[1], intervals[i][1]);
            } else {
                ret.push_back(currInterval);
                currInterval = intervals[i];
            }
        }
        ret.push_back(currInterval);
        return ret;
    }
};