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

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> mem1 (size+2, 0);
        vector<int> mem2 (size+2, 0);
        mem1[2] = nums[0];
        for (int i = 1; i < size-1; ++i) {
            mem1[i+2] = max(mem1[i+1], nums[i] + mem1[i]);
            mem2[i+2] = max(mem2[i+1], nums[i] + mem2[i]);
        }
        mem2[size+1] = max(mem2[size], nums[size-1] + mem2[size-1]);
        return max(mem1[size], mem2[size+1]);
    }
};