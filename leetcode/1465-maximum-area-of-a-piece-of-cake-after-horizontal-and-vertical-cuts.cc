// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Medium
// June 3rd, 2021 Coding Challenge

#include<vector>

using namespace std;

class Solution {
    int maxArea = 0;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int leftWidth = 0;
        int leftHeight = 0;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for (int &x: horizontalCuts) {
            for (int &y: verticalCuts) {
                maxArea = max((y-leftWidth)*(x-leftHeight), maxArea);
                leftWidth = y;
            }
            leftHeight = x;
        }
        return maxArea;
    }

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        vector<int> vcuts;
        for (int i = 0; i < verticalCuts.size(); ++i) {
            if (i == 0) vcuts.push_back(verticalCuts[i]);
            else {
                vcuts.push_back(verticalCuts[i]-verticalCuts[i-1]);
            }
        }
        vector<int> hcuts;
        for (int i = 0; i < horizontalCuts.size(); ++i) {
            if (i == 0) hcuts.push_back(horizontalCuts[i]);
            else {
                hcuts.push_back(horizontalCuts[i]-horizontalCuts[i-1]);
            }
        }
        
        long long int x = *max_element(vcuts.begin(), vcuts.end());
        long long int y = *max_element(hcuts.begin(), hcuts.end());
        cout << x << ' ' << y << endl;
        return (int)(x%mod*y%mod);
    }
};