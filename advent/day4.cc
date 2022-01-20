#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
using namespace std;

bool checkWin(vector<unordered_set<int>> board) {
    for (unordered_set<int> & s: board) {
        if (s.empty()) return true;
    }
    return false;
}

int main() {
    vector<int> v1 (12, 0);
    vector<string> in;
    
    string input;
    cin >> input;
    stringstream ss (input);
    while (ss.good()) {
        string substr;
        getline( ss, substr, ',' );
        in.push_back( substr );
    }

    int num;
    vector<vector<unordered_set<int>>> boards;
    bool done = false;
    while (!done) {
        vector<unordered_set<int>> b(10);
        for (int i = 0; i < 25; ++i) {
            if (!(cin >> num)) {
                done=true;
                break;
            }
            b[i/5].insert(num);
            b[5 + (i%5)].insert(num);
        }
        if (!done) boards.push_back(b);
    }
    unordered_set<int> finished;
    for (string &x: in) {
        int num = stoi(x);
        int i = 0;
        for (vector<unordered_set<int>> &b: boards) {
            for (unordered_set<int> &r: b) {
                r.erase(num);
            }
            if (finished.find(i) != finished.end() || checkWin(b)) {
                finished.insert(i);
            }
            if (finished.size() == boards.size()) {
                int win = 0;
                for (int i = 0; i < 5; ++i) {
                    unordered_set<int> r =  b[i];
                    for (int n: r) {
                        win += n;
                    }
                }
                cout << win*num << endl;
                return 0;
            }
            ++i;
        }
    }
    // return count;
}