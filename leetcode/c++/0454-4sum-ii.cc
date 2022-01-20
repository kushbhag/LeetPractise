// https://leetcode.com/problems/4sum-ii/
// Medium
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// class Solution {
// public:
//     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//         int size = A.size();
//         unordered_map<int, unordered_map<int, int>> m;
//         int count = 0;
//         for (int a = 0; a < size; ++a) {
//             int num = A[a];
//             if (m[0][num]) {
//                 count += m[0][num];
//             }
//             for (int b = 0; b < size; ++b) {
//                 int bCheck = num + B[b];
//                 if (m[1][bCheck]) {
//                     count += m[1][bCheck];
//                     break;
//                 }
//                 num = bCheck;
//                 for (int c = 0; c < size; ++c) {
//                     int cCheck = num + C[c];
//                     if (m[2][cCheck]) {
//                         count += m[2][cCheck];
//                         break;
//                     }
//                     num = cCheck;
//                     for (int d = 0; d < size; ++d) {
//                         num += D[d];
//                         if (num == 0) ++ count;
//                     }
//                     m[2][cCheck] = count;
//                 }
//                 m[1][bCheck] = count;
//             }
//             m[0][A[a]] = count;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        unordered_map<int, int> m1;
        for (auto a: A) {
            for (auto b: B) {
                ++m1[a + b];
            }
        }
        int count = 0;
        for (auto c: C) {
            for (auto d: D) {
                if (m1[-(c + d)]) {
                    count += m1[-(c + d)];
                }
            }
        }
        return count;
    }
};