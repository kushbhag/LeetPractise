// https://leetcode.com/problems/counting-bits/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        int div = 1;
        vector<int> v (n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (div*2 == i) {
                div *= 2;
                v[i] = 1;
            } else {
                v[i] = v[i-div] + 1;
            }   
        }
        return v;
    }
};