#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
using namespace std;

int main() {
    vector<long long> v (10, 0);
    unordered_map<int, int> m;
    
    string input;
    getline(cin, input);
    stringstream ss (input);
    while (getline(ss, input, ',')) {
        v[stoi(input)]++;
    }
    for (int i = 0; i < 256; ++i) {
        long long temp = v[0];
        for (int j = 0; j < 8; ++j) {
            v[j] = v[j+1];
        }
        v[8] = temp;
        v[6] += temp;
    }
    long long count = 0;
    for (long long &n: v) {
        count = (n + count);
    }
    cout << count << endl;
}