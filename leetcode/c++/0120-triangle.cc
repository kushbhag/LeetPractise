// https://leetcode.com/problems/triangle/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> v (size, vector<int> (size, INT_MAX));
        v[0][0] = triangle[0][0];
        for (int i = 0; i < size-1; ++i) {
            for (int j = 0; j <= i; ++j) {
                v[i+1][j] = min(v[i+1][j], triangle[i+1][j] + v[i][j]);
                v[i+1][j+1] = min(v[i+1][j+1], triangle[i+1][j+1] + v[i][j]);
            }
        }
        int m = INT_MAX;
        for (int i = 0; i < size; ++i) {
            m = min(v[size-1][i], m);
        }
        return m;
    }
};