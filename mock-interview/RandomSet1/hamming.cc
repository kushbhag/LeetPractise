#include<math.h>
#include<iostream>
using namespace std;
/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int basex;
        if (x != 0) basex = floor(log2(x));
        else basex = -1;
        int basey;
        if (y != 0) basey = floor(log2(y));
        else basey = -1;
        int res = 0;
        
        while (x > 0 || y > 0){
            if (x <= 0 && y <= 0) return res;
            if (basex != basey) {
                res ++;
                if (basey > basex){
                    y = y - pow(2, basey);
                    if (y > 0) basey = floor(log2(y));
                    else basey = -1;
                }else{
                    x = x - pow(2, basex);
                    if (x > 0) basex = floor(log2(x));
                    else basex = -1;
                }
            } else {
                 y = y - pow(2, basey);
                if (y > 0) basey = floor(log2(y));
                else basey = -1;
                x = x - pow(2, basex);
                if (x > 0) basex = floor(log2(x));
                else basex = -1;
            }
        }
        return res;
    }
};