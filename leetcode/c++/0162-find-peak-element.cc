// https://leetcode.com/problems/find-peak-element/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, size = nums.size(), hi = size - 1, mid;
        if (size == 1) return 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (mid == 0) {
                if (nums[mid+1] < nums[mid]) {
                    return mid;
                }
                lo = mid + 1;
            } else if (mid == size-1) {
                if (nums[mid-1] < nums[mid]) {
                    return mid;
                }
                hi = mid - 1;
            } else if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]) {
                return mid;
            } else if (nums[mid-1] > nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
