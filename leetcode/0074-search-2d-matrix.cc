// https://leetcode.com/problems/search-a-2d-matrix/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

// O(log(n) + log(m))
class Solution {
    int height;
    int binarySearch(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = height-1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (matrix[mid][0] <= target) {
                if (mid == height -1 || (mid+1 < height && matrix[mid+1][0] > target)) {
                    return mid;
                } else {
                    lo = mid+1;
                }
            } else {
                hi = mid-1;
            }
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int width = matrix[0].size();
        height = matrix.size();
        int i = binarySearch(matrix, target);
        if (i != -1 && binary_search(matrix[i].begin(), matrix[i].end(), target)) {
            return true;
        }
        return false;
    }
};