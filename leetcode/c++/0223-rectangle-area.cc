// https://leetcode.com/problems/rectangle-area/
// Medium
// Mock

#include<algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C - A)*(D - B);
        int areaB = (G - E)*(H - F);
        int X = 0;
        if ((E <= C && E >= A) || (A <= G && A >= E)) {
            X = min (C, G) - max(A, E);
        }
        int Y = 0;
        if ((H <= D && H >= B) || (D <= H && D >= F)) {
            Y = min (D, H) - max(B, F);
        }
        int total = 0;
        if (X <= 0 || Y <= 0) total = 0;
        else {
            total = X*Y;
        }
        return areaA - total + areaB;
    }
};