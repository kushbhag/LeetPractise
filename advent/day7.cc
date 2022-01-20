#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
using namespace std;

int main() {
    int count = 0, n=0;
    long maxNum = LONG_MIN, minNum = LONG_MAX;
    string input;
    getline(cin, input);
    stringstream ss (input);
    // cout << input << endl;
    vector<long> v;
    while (getline(ss, input, ',')) {
        minNum = min(stol(input), minNum);
        maxNum = max(stol(input), maxNum);
        v.push_back(stol(input));
        // ++n;
    }
    long cost = 0, minCost = LONG_MAX;
    for (int i = minNum; i < maxNum; ++i) {
        cost = 0;
        for (long &n: v) {
            int x = abs(i-n);
            cost += (x*(x+1))/2;
        }
        minCost = min(cost, minCost);
    }
    cout << minNum << ' ' << maxNum << endl;
    cout << count << ' ' << n << endl;
    cout << minCost << endl;
    // cout << count << endl;
}