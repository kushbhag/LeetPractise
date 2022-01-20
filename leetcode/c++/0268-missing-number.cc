// https://leetcode.com/problems/missing-number/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (size * (size+1))/2, sum1 = 0;
        for (int &x: nums) {
            sum1 += x;
        }
        return sum-sum1;
    }
};