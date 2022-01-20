#include<vector>
#include<iostream>
#include<climits>
#include <queue>
using namespace std;

int main() {
    int prev = INT_MAX;
    int x = 0, count = 0;
    int num;
    queue<int> q;
    for (int i = 0; i < 2; ++i) {
        cin >> num;
        x += num;
        q.push(num);
    }
    while (cin >> num) {
        q.push(num);
        x += num;
        if (x > prev) ++count;
        prev = x;
        x -= q.front();
        q.pop();
    }
    cout << count << endl;
    // return count;
}