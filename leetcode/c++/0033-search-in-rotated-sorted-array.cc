// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0, high = size - 1, mid = (low + high) / 2;
        int ret = -1;
        while (low <= high) {
            // cout << nums[low] << ' ' << nums[mid] << ' ' << nums[high] << endl;
            if (nums[low] == target) return low;
            if (nums[high] == target) return high;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                if (nums[mid] < nums[high] && nums[high] < target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] > target) {
                if (nums[mid] > nums[low] && nums[low] > target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            mid = (low + high) / 2;
        }
        return ret;
    }
};