// https://leetcode.com/problems/longest-increasing-subsequence/
// Medium

#include<vector>

using namespace std;

// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), maxSoFar = 1;
        vector<int> v (size, 1);
        int curr, temp;
        for (int i = 1; i < size; ++i) {
            temp = 1;
            for (int j = 0; j < i; ++j) {
                curr = v[j]+1;
                if (nums[j] < nums[i] && curr > temp) {
                    temp = curr;
                }
            }
            v[i] = temp;
            maxSoFar = max(temp, maxSoFar);
        }
        return maxSoFar;
    }
};