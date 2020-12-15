// https://leetcode.com/problems/boats-to-save-people/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int lo, hi, boats = 0;
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int> ());
        lo = 0;
        hi = people.size() - 1;
        while (lo < hi) {
            ++boats;
            if (people[hi] + people[lo] <= limit) --hi;
            ++lo;
        }
        return boats;
    }
};