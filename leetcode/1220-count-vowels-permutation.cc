// https://leetcode.com/problems/count-vowels-permutation/
// Hard
// July 4th, 2021 Challenge

class Solution {
    const long long int d = 1000000007;
public:
    int countVowelPermutation(int n) {
        long long int v[5];
        long long int prev[5];
        v[0] = v[1] = v[2] = v[3] = v[4] = 0;
        prev[0] = prev[1] = prev[2] = prev[3] = prev[4] = 1;
        for (int i = 1; i < n; ++i) {
            // For A
            v[1] += (prev[0] + prev[2]) % d;
            // For E
            v[0] += (prev[1] + prev[2] + prev[4]) % d;
            v[2] += (prev[1] + prev[3]) % d;
            // For I
            v[3] += prev[2] % d;
            v[4] += (prev[2] + prev[3]) % d;
            for (int i = 0; i < 5; ++i) {
                prev[i] = v[i];
                v[i] = 0;
            }
        }
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum = (sum + prev[i]) % d;
        }
        return sum % d;
    }
};