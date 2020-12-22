// https://leetcode.com/problems/pascals-triangle/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back(vector<int> (1, 1));
        int num = 1;
        for (; num < numRows; ++num) {
            vector<int> v (1, 1);
            for (int i = 1; i < num; ++i) {
                v.push_back(ret[num-1][i-1] + ret[num-1][i]);
            }
            v.push_back(1);
            ret.push_back(v);
        }
        return ret;
    }
};