// https://leetcode.com/problems/house-robber-ii/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int first, firstP = 0, firstPP = 0;
        int second, secondP = 0, secondPP = 0;
        int maxSoFar = 0, size = nums.size();

        first = max (firstP, nums[0] + firstPP);
        firstP = first;
        for (int i = 1; i < size-1; ++i) {
            first = max (firstP, nums[i] + firstPP);
            second = max (secondP, nums[i] + secondPP);
            firstPP = firstP;
            firstP = first;
            secondPP = secondP;
            secondP = second;
        }
        second = max(secondP, nums[size-1] + secondPP);
        return max (first, second);
    }
};