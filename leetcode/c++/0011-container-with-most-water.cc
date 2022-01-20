// https://leetcode.com/problems/container-with-most-water/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p = 0, maxCount = 0, tempCount = 0, size = height.size();
        int q = size - 1;
        while (p < q) {
            maxCount = max(min(height[p],height[q])*(q-p),maxCount);
            if (height[p] < height[q]) {
                ++p;
            } else {
                --q;
            }
            // Can optimize more by reducing both p and q to the point where
            //      where both their heights are larger than the current min
        }
        return maxCount;
    }
};