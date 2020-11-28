#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<math.h>
using namespace std;

int memoRollsToTarget(int d, int f, int target, unordered_map<string, int>& m) {
    if (target <= 0 || d <= 0 || f <= 0 || d > target) {
        return 0;
    } else if  (d == 1) {
        return f >= target ? 1 : 0;
    } else if (pow(f, d) < target) {
        return 0;
    }
    int total = 0;
    string key = to_string(d) + to_string(f) + to_string(target);
    int value = m[key];
    if (value > 0) {
        // cout << "optimized" <<  endl;
        return value;
    }
    for (int i = 1; i <= f; i++) {
        string otherKey = to_string(d-1) + to_string(f) + to_string(target-i);
        if (target-i < 0 || d-1 > target-i) {
            continue;
        } else if (m[otherKey] > 0) {
            total += m[otherKey];
        } else {
            int temp = memoRollsToTarget(d-1, f, target-i, m);
            if (temp > 0) {
                m[otherKey] = temp;
                total += temp;
            }
        }
    }
    if (total > 0) {
        m[key] = total;
    }
    return total;
}

int dp[31][1001] = {};
int numRollsToTarget(int d, int f, int target) {
    if (target <= 0 || d <= 0) {
        return d == target;
    }
    if (dp[d][target]) return dp[d][target];
    int total = 0;
    for (int i = 1; i <= f; i++) {
        total += numRollsToTarget(d-1, f, target-i);
    }
    dp[d][target] = total;
    return total;
}

int main () {
    cout << numRollsToTarget(5, 5, 10);
    for (int i = 1; i < 31; i ++ ){
        for (int j = 1; j < 1001; j++) {
            if (dp[i][j]) {
                cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
}