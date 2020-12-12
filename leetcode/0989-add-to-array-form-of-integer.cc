// https://leetcode.com/problems/add-to-array-form-of-integer/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int m, carry = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            m = K % 10;
            A[i] += carry + m;
            if (A[i] >= 10) {
                A[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            K/=10;
        }
        if (K > 0) {
            while (K != 0) {
                m = (K % 10) + carry;
                if (m >= 10) {
                    m -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                A.insert(A.begin(), m);
                K /= 10;
            }
        }
        if (carry == 1) {
            A.insert(A.begin(), carry);
        }
        return A;
    }
};