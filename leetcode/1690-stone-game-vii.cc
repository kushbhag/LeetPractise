// https://leetcode.com/problems/stone-game-vii/
// Medium
// June 11, 2021 Challenge

#include<vector>

using namespace std;

class Solution {
    vector<vector<int>> mem;
    int stoneGameVII(vector<int>& stones, int lo, int hi, int sum) {
        if (lo == hi) {
            mem[lo][hi] = 0;
            return 0;
        } else if (mem[lo][hi] != INT_MIN) {
            return mem[lo][hi];
        }
        int xDiff = sum-stones[lo]-stoneGameVII(stones, lo+1, hi, sum-stones[lo]);
        int yDiff = sum-stones[hi]-stoneGameVII(stones, lo, hi-1, sum-stones[hi]);
        mem[lo][hi] = max(xDiff, yDiff);
        return max(xDiff, yDiff);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int sum = 0;
        int size = stones.size();
        for (int i = 0; i < size; ++i) {
            mem.push_back(vector<int> (size, INT_MIN));
            sum += stones[i];
        }
        
        stoneGameVII(stones, 0, size-1, sum);
        // for (int i = 0; i < size; ++i) {
        //     for (int j = 0; j < size; ++j) {
        //         if (mem[i][j] == INT_MIN) cout << 0 << ' ';
        //         else cout << mem[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return mem[0][size-1];
    }
};