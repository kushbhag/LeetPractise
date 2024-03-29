// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int size = points.size();
        int curr = points[0][1], count = 1;
        for (int i = 1; i < size; ++i) {
            if (curr < points[i][0]) {
                curr = points[i][1];
                ++count;
            } else {
                curr = min(curr, points[i][1]);
            }
        }
        return count;
    }
};