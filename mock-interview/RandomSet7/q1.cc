#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> m;
    int finalLength = 0;
    for (auto &c: chars) {
        m[c] ++;
    }
    for (auto &strings: words) {
        if (strings.length() > chars.length()) {
            continue;
        } else {
            unordered_map<char, int> tempM = m;
            bool add = true;
            for (auto &c: strings) {
                if (tempM[c]-- < 0) {
                    add = false;
                    break;
                }
            }
            finalLength = add ? finalLength + strings.length() : finalLength;
        }
    }
    return finalLength;
}

int main() {


}