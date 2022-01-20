// https://leetcode.com/problems/climbing-stairs/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v (n+1, 0);
        v[0] = 1;
        v[1] = 1;
        for (int i = 2; i <= n; ++i) {
            v[i]=v[i-1]+v[i-2];
        }
        // Can optimize by just using integers rather than a vector
        return v[n];
    }
};

// Constant space
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prev = 2, prevprev = 1;
        int curr;
        for (int i = 3; i <= n; ++i) {
            curr = prev + prevprev;
            prevprev = prev;
            prev = curr;
        }
        return prev;
    }
};