// https://leetcode.com/problems/integer-break/
// Medium

#include<vector>

using namespace std;

class Solution {
    vector<int> v;

    int integerBreakRec(int n) {
        if (v[n] != -1) return v[n];
        int maxP = 0;
        for (int i = 1; i < n; ++i) {
            maxP = max(maxP, i * (integerBreakRec(n-i)));
        }
        v[n] = maxP;
        return maxP;
    }

public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        v = vector<int> (n+1, -1);
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        int i = integerBreakRec(n);
        return i;
    }
};