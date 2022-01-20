// https://leetcode.com/problems/push-dominoes/
// Medium
// July 21, 2021 Challenge

#include<string>

using namespace std;

class Solution {
    int len;
    
    void pushDominoesLeft(string &dominoes, int lo, int hi) {
        while (lo <= hi) {
            dominoes[lo] = 'L';
            dominoes[hi] = 'L';
            lo++;
            hi--;
        }
    }
    void pushDominoesRight(string &dominoes, int lo, int hi) {
        while (lo <= hi) {
            dominoes[lo] = 'R';
            dominoes[hi] = 'R';
            lo++;
            hi--;
        }
    }
    void pushDominoesLoHi(string& dominoes, int lo, int hi) {
        while (lo < hi) {
            if (lo >= 0) dominoes[lo] = 'R';
            if (hi < len) dominoes[hi] = 'L';
            lo++;
            hi--;
        }
    }
public:
    string pushDominoes(string dominoes) {
        len = dominoes.length();
        int lo = 0, hi = 0;
        while (hi < len) {
            if (dominoes[hi] == 'R') {
                if (dominoes[lo] == 'R') {
                    pushDominoesRight(dominoes, lo, hi);
                }
                lo = hi;
            } else if (dominoes[hi] == 'L') {
                if (dominoes[lo] == 'R') {
                    pushDominoesLoHi(dominoes, lo, hi);
                } else {
                    pushDominoesLeft(dominoes, lo, hi);
                }
                lo = hi;
            }
            ++hi;
        }
        if (lo >= 0 && dominoes[lo] == 'R') {
            pushDominoesRight(dominoes, lo, hi-1);
        }
        return dominoes;
    }
};