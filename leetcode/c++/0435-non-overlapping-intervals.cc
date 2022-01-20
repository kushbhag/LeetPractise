// https://leetcode.com/problems/non-overlapping-intervals/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int size = intervals.size();
        int left = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            if (left > intervals[i][0]) {
                left = min(left, intervals[i][1]);
                count++;
            } else {
                left = intervals[i][1];
            }
        }
        return count;
    }
};