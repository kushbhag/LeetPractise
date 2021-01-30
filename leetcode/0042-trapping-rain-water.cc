// https://leetcode.com/problems/trapping-rain-water/
// Hard
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxPool = 0, size = height.size();
        int currPool = 0, currHeight = 0;
        int index = 0;
        while (index < size && height[index] == 0) { index++; }
        if (index == size) return 0;
        currHeight = height[index];
        for (int i = index+1; i < size; ++i) {
            if (height[i] >= currHeight) {
                maxPool += currPool;
                currPool = 0;
                currHeight = height[i];
                index = i;
            } else {
                currPool += currHeight - height[i];
            }
        }
        int lastIndex = size-1;
        while (lastIndex > index && height[lastIndex] == 0) { lastIndex--; }
        currPool = 0;
        currHeight = height[lastIndex];
        for (int i = lastIndex; i >= index; --i) {
            if (height[i] >= currHeight) {
                maxPool += currPool;
                currPool = 0;
                currHeight = height[i];
            } else {
                currPool += currHeight - height[i];
            }
        }
        return maxPool;
    }
};