// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size(), sizeB = B.size();
        if (sizeA == 0 || sizeB == 0) return 0;
        vector<int> mem (sizeA + 1, 0);
        int maxSoFar = 0;

        for (int i = 1; i <= sizeB; ++i) {
            for (int j = sizeA; j >= 1; --j) {
                if (A[j-1] == B[i-1]) {
                    mem[j] = mem[j-1]+1;
                    maxSoFar = maxSoFar < mem[j] ? mem[j] : maxSoFar;
                } else {
                    mem[j] = 0;
                }
            }
        }
        return maxSoFar;
    }
};