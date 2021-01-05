// https://leetcode.com/problems/house-robber/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSoFar = 0, size = nums.size();
        if (size == 0) return 0;
        int first, second, firstPrev = 0, firstPrevPrev = 0, secondPrev = 0, secondPrevPrev = 0;

        first = max(firstPrev, nums[0] + firstPrevPrev);
        maxSoFar = max(maxSoFar, first);
        for (int i = 0; i < size; ++i) {
            first= max(firstPrev, nums[i] + firstPrevPrev);
            second = max(secondPrev, nums[i] + secondPrevPrev);
            firstPrevPrev = firstPrev;
            firstPrev = first;
            secondPrevPrev = secondPrev;
            secondPrev = second;
        }
        return max(first, second);
    }
};