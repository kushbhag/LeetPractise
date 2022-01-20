// https://leetcode.com/problems/add-to-array-form-of-integer/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int m, carry = 0, temp;
        vector<int> ret;
        for (int i = A.size() - 1; i >= 0; --i) {
            m = K % 10;
            temp = A[i] + carry + m;
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ret.push_back(temp);
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
                ret.push_back(m);
                K /= 10;
            }
        }
        if (carry == 1) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};