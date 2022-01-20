// https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Medium
// July 22, 2021 Challenge

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        int minNums [size], maxNums[size];
        maxNums[0] = nums[0];
        minNums[size-1] = nums[size-1];
        for (int i = 1; i < size; ++i) {
            maxNums[i] = max(nums[i], maxNums[i-1]);
            minNums[size-i-1] = min(nums[size-i-1], minNums[size-i]);
        }
        for (int i = 0; i < size-1; ++i) {
            if (maxNums[i] <= minNums[i+1]) return i+1;
        }
        return size;
    }
};

class Solution1 {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        int maxSoFar = nums[0], prevMax = nums[0];
        int ans = INT_MAX;
        for (int i = 0; i < size-1; ++i) {
            maxSoFar = max(nums[i], maxSoFar);
            if (maxSoFar <= nums[i+1] && ans == INT_MAX) {
                ans = i+1;
                prevMax = maxSoFar;
            } else if (prevMax > nums[i+1]) {
                // cout << prevMax << ' ' << nums[i] << endl;
                ans = INT_MAX;
            }
        }
        return ans;
    }
};
