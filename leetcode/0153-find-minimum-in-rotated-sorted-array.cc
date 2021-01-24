// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Medium

#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        int mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            //cout << lo << ' ' << mid << ' ' << hi << endl;
            if (nums[lo] < nums[hi]) return nums[lo];
            else if (mid == lo) lo = mid + 1;
            else if (mid == hi) hi = mid - 1;
            else if (nums[mid] > nums[lo]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};