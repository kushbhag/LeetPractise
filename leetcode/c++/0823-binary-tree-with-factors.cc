// https://leetcode.com/problems/binary-trees-with-factors/
// Medium

#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    unordered_map<int, long> m;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        long sum = 0;
        for (int i = 0; i < size; ++i) {
            int currSum = 1;
            for (int j = 0; j <= i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    currSum = (currSum + m[arr[j]] * m[arr[i] / arr[j]]) % 1000000007;
                }
            }
            sum = (sum + currSum) % 1000000007;
            m[arr[i]] = currSum;
        }
        return sum;
    }
};
