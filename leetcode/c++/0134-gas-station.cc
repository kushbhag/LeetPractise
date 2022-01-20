// https://leetcode.com/problems/gas-station/
// Medium
#include<vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size(), check = 0;

        for (int i = 0; i < size; ++i) {
            check = 0;
            int j = i;
            do {
                check += gas[j] - cost[j];
                if (check < 0) break;
                ++j;
                if (j >= size) j = 0;
            } while (j != i);
            if (check >= 0) return i;
            else if (j > i) {
                i = j;
            } else if (i > j) {
                return -1;
            }
        }
        return -1;
    }
};

