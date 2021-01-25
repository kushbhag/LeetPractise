// https://leetcode.com/problems/palindrome-number/
// Easy

class Solution {
    int temp, count = 1, div = 1, bottom = 10;
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        temp = x;
        while (temp > 0) {
            temp /= 10;
            count *= 10;
        }
        count /= 10;
        while(count > bottom) {
            if ((x%bottom)/div != (x/count)%10) {
                return false;
            }
            count /= 10;
            bottom *= 10;
            div *= 10;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int y = x;
        int sum = 0;
        while (x > 0) {
            if (sum > INT_MAX / 10) return false;
            sum = (sum*10) + x%10;
            x /= 10;
        }
        return y == sum;
    }
};