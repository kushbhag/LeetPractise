// https://leetcode.com/problems/increasing-triplet-subsequence/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int &n: nums) {
            if (n > second && second > first) {
                return true;
            } else if (n <= first) {
                first = n;
            } else if (n < second) {
                second = n;
            }
        }
        return false;
    }
};
