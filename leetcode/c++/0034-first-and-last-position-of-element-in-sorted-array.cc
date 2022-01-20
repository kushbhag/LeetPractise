// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Medium
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret { -1, -1 };
        int size = nums.size();
        int lpointer = 0;
        int rpointer = size - 1;
        int center = size / 2;

        int leftPointer = size - 1;
        int rightPointer = -1;
        while (lpointer <= rpointer) {
            // cout << lpointer << ' ' << rpointer <<' ' << center << endl;
            if (nums[center] < target) {
                lpointer = max(lpointer + 1, center);
            } else if (nums[center] > target) {
                rpointer = min(rpointer - 1, center);
            } else if (nums[center] == target) {
                leftPointer = min(leftPointer, center);
                rpointer = min(rpointer - 1, center);
            }
            center = (lpointer + rpointer) / 2;
        }
        lpointer = 0;
        rpointer = size - 1;
        center = size / 2;
        while (lpointer <= rpointer) {
            // cout << lpointer << ' ' << rpointer <<' ' << center << endl;
            if (nums[center] < target) {
                lpointer = max(lpointer + 1, center);
            } else if (nums[center] > target) {
                rpointer = min(rpointer - 1, center);
            } else if (nums[center] == target) {
                rightPointer = max(rightPointer, center);
                lpointer = max(lpointer + 1, center);
            }
            center = (lpointer + rpointer) / 2;
        }
        if (rightPointer != -1) {
            ret[0] = leftPointer;
            ret[1] = rightPointer;
        }

        return ret;
    }
};