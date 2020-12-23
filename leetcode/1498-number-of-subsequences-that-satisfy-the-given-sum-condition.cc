// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Medium

#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Has overflow, but logic is correct
class Solution {
    int len;
    unordered_map<int, long> m;
    long long nchoosek (int n, int k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        long long result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }

    long long nchoose (int n) {
        if (n <= 0) return 0;
        if (m.find(n) != m.end()) return m[n];
        long total = 0;
        for (int i = 1; i <= n; ++i) {
            total += nchoosek(n, i);
        }
        m[n] = total;
        return total;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        len = nums.size();
        long total = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (nums[i] + nums[j] <= target) {
                    total = (total + 1 + (nchoose(j-i-1))) % 1000000007;
                }
            }
        }
        return total;
    }
};