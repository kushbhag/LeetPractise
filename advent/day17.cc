#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;

unordered_map<string, string> m;
unordered_map<string, long> counts;
unordered_set<string> u;

int main() {
    string input, n1, n2;
    vector<vector<long>> v;
    string starting;
    // getline(cin, input);
    int minX = 137, maxX = 171;
    int minY = -98, maxY = -73;
    // minX = 20;
    // maxX = 30;
    // minY = -10;
    // maxY = -5;
    int x = 0, y = 0;
    int startVy = 0, startVx = 1;
    int maxPos = 0;
    int count = 0;
    for (int vx = 0; vx < 400; ++vx) {
        for (int vy = -300; vy < 300; ++vy) {
            int tempVx = vx, tempVy = vy;
            y = 0;
            x = 0;
            while (1) {
                x += tempVx;
                y += tempVy;
                // m = max(m, y);
                tempVx = max(tempVx-1, 0);
                tempVy--;
                if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
                    ++count;
                    // maxPos = max(maxPos, m);
                    break;
                } else if (y < minY) {
                    if (vx == 6 && vy == 0) {
                        cout << 'H' << endl;
                    }
                    break;
                }
            }
        }
    }
    cout << count << endl;
}