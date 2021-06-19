// https://leetcode.com/problems/sliding-window-maximum/
// Hard

#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        deque<int> d;
        int size = nums.size();
        vector<int> solution;
        d.push_back(0);
        for (int i = 1; i < size; ++i) {
            while (!d.empty() && nums[d.back()] <= nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            if (i-d.front() >= k) d.pop_front();
            if (i >= k-1) {
                solution.push_back(nums[d.front()]);
            }
        }
        return solution;
    }
};