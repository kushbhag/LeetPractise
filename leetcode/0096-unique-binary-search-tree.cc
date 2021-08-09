// https://leetcode.com/problems/unique-binary-search-trees/
// Medium

#include<vector>

using namespace std;

class Solution {
    vector<int> v;
    int numTreesRec(int n) {
        if (n == 0 || n == 1) return 1;
        else if (v[n] != -1) return v[n];
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += numTreesRec(i-1) * numTreesRec(n-i);
        }
        v[n] = sum;
        return sum;
    }
public:
    int numTrees(int n) {
        v = vector<int> (n+1, -1);
        return numTreesRec(n);
    }
};
    