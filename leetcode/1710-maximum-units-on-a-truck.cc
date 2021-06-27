// https://leetcode.com/problems/maximum-units-on-a-truck/
// Easy
// June 14th, 2021 Challenge

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort (boxTypes.begin(), boxTypes.end(), [] (const auto &l, const auto &r) {
            return l[1] > r[1];
        });
        int units = 0;
        for (vector<int> &v: boxTypes) {
            truckSize -= v[0];
            if (truckSize < 0) {
                v[0] += truckSize;
                units += v[0] * v[1];
                break;
            } else {
                units += v[0] * v[1];
            }
        }
        return units;
    }
};