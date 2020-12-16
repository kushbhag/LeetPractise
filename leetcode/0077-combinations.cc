// https://leetcode.com/problems/combinations/
// Medium

#include<vector>

using namespace std;

class Solution {
    int N;
    void combineRec(int k, int start, vector<int>& temp,vector<vector<int>>& v) {
        if (k == 0) {
            v.push_back(temp);
            return;
        }
        for (int i = start; i <= N; ++i) {
            temp.push_back(i);
            combineRec(k-1, start+1, temp, v);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        N = n;
        vector<vector<int>> ret;
        vector<int> temp;
        combineRec(k, 1, temp, ret);
        return ret;
    }
};