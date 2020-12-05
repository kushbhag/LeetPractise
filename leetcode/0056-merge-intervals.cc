// https://leetcode.com/problems/merge-intervals/
// Medium
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // I could've optimized more by sorting it first and then merging the intervals
        vector<vector<int>> ret;
        if (intervals.empty()) return intervals;
        int size = intervals.size();

        for (int i = 0; i < size; ++i) {
            if (ret.empty()) ret.push_back(intervals[i]);
            else {
                vector<int> temp = intervals[i];
                for (int j = 0; j < ret.size(); ++j) {
                    if ((ret[j][0] >= temp[0]  && ret[j][0] <= temp[1]) || 
                        (temp[0] >= ret[j][0]  && temp[0] <= ret[j][1])) {
                        temp = vector<int> { min(temp[0], ret[j][0]), max(temp[1], ret[j][1])};
                        ret[j] = temp;
                        ret.erase(ret.begin() + j--);
                    }
                }
                ret.push_back(temp);
            }
        }
        return ret;
    }
};