#include<vector>
#include<iostream>
#include<climits>
#include <string>
using namespace std;

int main() {
    int h=0, d =0, aim = 0;
    string s;
    int x;
    while (cin >> s) {
        cin  >> x;
        if (s == "forward") {
            h += x;
            d += (aim*x);
        } else if (s == "down") {
            // d += x;
            aim += x;
        } else if (s == "up") {
            // d -= x;
            aim -= x;
        }
    }
    cout << d << ' ' << h << endl;
    cout << d * h << endl;
    // return count;
}