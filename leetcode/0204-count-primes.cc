// https://leetcode.com/problems/count-primes/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> v (n, true);
        int primes = 1;
        for (int i = 3; i < n; i+=2) {
            if (v[i]) ++primes;
            if (INT_MAX / i < i) continue;
            for (int j = i*i; j < n; j += i) {
                v[j] = false;
            }
        }
        return primes;
    }
};