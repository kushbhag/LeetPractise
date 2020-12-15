// https://leetcode.com/problems/merge-sorted-array/
// Easy

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1temp (nums1.begin(), nums1.begin() + m);
        int l=m-1, r=n-1, i=m+n-1;
        while (i>= 0) {
            if (l < 0) nums1[i] = nums2[r--];
            else if (r < 0) nums1[i] = nums1[l--];
            else {
                nums1[i] = nums1[l] > nums2[r] ? nums1[l--] : nums2[r--];
            }
            --i;
        }
    }
};