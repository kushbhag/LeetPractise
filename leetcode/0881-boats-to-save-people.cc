// https://leetcode.com/problems/boats-to-save-people/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int lo, hi, boats = 0;
    vector<int> copy;
    void findAndSetZero(vector<int>& people, int find) {
        int low = 0, high = size - 1, mid = (low + high) / 2;
        while (low <= high) {
            if (copy[mid] > find) {
                low = mid + 1;
            } else if (copy[mid] < find) {
                high = mid - 1;
            } else if (copy[mid] == find) {
                people[mid] = 0;
                break;
            }
            mid = (low + high) / 2;
        }
    }
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int> ());
        lo = 0;
        hi = people.size() - 1;
        while (lo < hi) {
            ++boats;
            if (people[hi] + people[lo] <= limit) --hi;
        }
        size = people.size();
        copy = people;
        for (int i = 0; i < size; ++i) {
            if (people[i] != 0) {
                people[i] = 0;
                findAndSetZero(people, limit-people[i]);
                ++boats;
            }
        }
        return boats;
    }
};