// https://leetcode.com/problems/candy/
// Hard
// June 27th, 2021 Challenge

#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, inc = 1;
        bool increment = false;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] == ratings[i-1]) {
                inc = 1;
            } else if (ratings[i] > ratings[i-1] && increment) {
                inc++;
            } else if (ratings[i] > ratings[i-1]) {
                inc = 2;
                increment = true;
            } else if (ratings[i] < ratings[i-1] && !increment) {
                inc++;
            } else if (ratings[i] < ratings[i-1]) {
                inc = 2;
                increment = false;
            }
            sum += inc;
        }
        return sum;
    }
};