#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
using namespace std;

int main() {
    vector<vector<int>> v (1000, vector<int> (1000, 0));
    
    string input;
    while (getline(cin, input)) {
        // cout << input << endl;
        stringstream ss (input);
        string x1, y1, x2, y2, temp;
        getline( ss, x1, ',' );
        getline( ss, y1, '-');
        getline( ss, temp, '>');
        getline( ss, x2, ',' );
        getline( ss, y2);
        int xx1 = stoi(x1), xx2 = stoi(x2), yy1 = stoi(y1), yy2 = stoi(y2);
        cout << xx1 << ' ' << yy1 << ' ' << xx2 << ' ' << yy2 << endl;
        if (xx1 == xx2) {
            for (unsigned int y = min(yy1, yy2); y <= max(yy1, yy2); ++y) {
                v[xx1][y]++;
            }
        } else if (yy1 == yy2) {
            for (unsigned int x = min(xx1, xx2); x <= max(xx1, xx2); ++x) {
                v[x][yy1]++;
            }
        } else if (abs(xx1 - xx2) == abs(yy1 - yy2)) {
            int x = xx1, y = yy1;
            for (unsigned int i = 0; i <= abs(xx1 - xx2); ++i) {
                v[x][y]++;
                if (x < xx2) ++x;
                else --x;
                if (y < yy2) ++y;
                else --y;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            // cout << v[i][j] << ' ';
            if (v[i][j] >= 2) ++count;
        }
        // cout << endl;
    }
    cout << count << endl;
    // while (ss.good()) {
    //     string substr;
    //     getline( ss, substr, ',' );
    //     in.push_back( substr );
    // }

    int num;
    // return count;
}