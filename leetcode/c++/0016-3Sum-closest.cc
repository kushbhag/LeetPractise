// https://leetcode.com/problems/3sum-closest/
// Medium
// July 27th, 2021

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minClosest = INT_MAX, closest = 0;
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            int lo = i+1, hi = size-1;
            while (lo < hi) {
                int t = nums[i] + nums[lo] + nums[hi];
                if (abs(target - t) < minClosest) {
                    if (t == target) return target;
                    closest = t;
                    minClosest = abs(target - t);
                }
                if (t > target) --hi;
                else ++lo;
            }
        }
        return closest;
    }
};