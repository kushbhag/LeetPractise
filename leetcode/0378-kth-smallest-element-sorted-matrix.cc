// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Medium

#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Simple O(n^2) and pq
        int size = matrix.size();
        priority_queue<int> pq;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (k == 0 && pq.top() > matrix[j][i]) {
                    pq.push(matrix[j][i]);
                    pq.pop();
                } else if (k != 0) {
                    pq.push(matrix[j][i]);
                    --k;
                }
            }
        }
        return pq.top();
    }
};