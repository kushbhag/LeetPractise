#include<string>
using namespace std;
/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        bool check = false;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == 'A') {
                a++;
                check = false;
                l = 0;
            } else if (s[i] == 'L'){
                if (check && l >= 2){
                    return false;
                }
                l ++;
                check = true;
            } else{
                check = false;
                l = 0;
            }
            if (a >= 2) return false;
        }
        return true;
    }
};