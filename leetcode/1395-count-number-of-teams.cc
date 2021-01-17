// https://leetcode.com/problems/count-number-of-teams/
// Medium
// Mock

#include<vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int size = rating.size();
        int count = 0;
        vector<int> v (size, 0);
        vector<int> v1 (size, 0);
        int curr, curr1, currRating;

        for (int i = 0; i < size; ++i) {
            curr = v[i];
            curr1 = v1[i];
            currRating = rating[i];
            for (int j = i+1; j < size; ++j) {
                if (rating[j] > currRating) {
                    count += curr;
                    ++v[j];
                }
                if (rating[j] < currRating) {
                    count += curr1;
                    ++v1[j];
                }
            }
        }
        return count;
    }
};