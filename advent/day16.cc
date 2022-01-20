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

unordered_map<char, string> m;
unordered_map<string, long> counts;
unordered_set<string> u;

string convertToBin(string s) {
    string ret = "";
    for (char &c: s) {
        ret += m[c];
    }
    return ret;
}

long convertToDec(string b) {
    long e = 1;
    long ret = 0;
    for (int i = b.length()-1; i >= 0; --i) {
        ret += ((b[i] - '0') * e);
        e *= 2;
    }
    return ret;
}

int version = 0;
int i = 0;
// int total = 0;

long literalPacket(string input) {
    bool br = false;
    string ret = "";
    while (!br) {
        if (input[i] == '0') {
            br = true;
        }
        i += 1;
        ret += input.substr(i, 4);
        i += 4;
    }
    return convertToDec(ret);
}

long operatorPacket(string input) {
    cout << i << ' ' << input.length() << endl;
    int id = convertToDec(input.substr(i, 3));
    i += 3;
    long ret = 0;
    if (id == 1) ret = 1;
    else if (id == 2) ret = LONG_MAX;
    else if (id == 3) ret = LONG_MIN;
    else if (id == 4) return literalPacket(input);

    int bitI = convertToDec(input.substr(i, 1));
    i += 1;
    bool lll = false;
    int len;
    if (bitI == 0) {
        lll = true;
        len = convertToDec(input.substr(i, 15));
        i += 15;
    } else {
        len = convertToDec(input.substr(i, 11));
        i += 11;
    }
    if (id == 5 || id == 6 || id == 7) {
        i += 3;
        long prev = operatorPacket(input);
        i += 3;
        long curr = operatorPacket(input);

        if (id == 5) ret = prev > curr ? 1 : 0;
        else if (id == 6) ret = prev < curr ? 1 : 0;
        else if (id == 7) ret = prev == curr ? 1 : 0;
        return ret;
    }

    bool cond = true;
    int until = i + len;
    int s = 0;
    while (cond) {
        // int v = convertToDec(input.substr(i, 3));
        i += 3;
        // version += v;
        long curr = operatorPacket(input);
        if (id == 0) ret += curr;
        else if (id == 1) ret *= curr;
        else if (id == 2) ret = min(ret, curr);
        else if (id == 3) ret = max(ret, curr);
        // cout << i <<' ' << input.length();
        if (lll && i >= until) {
            cond = false;
        } else if (!lll && ++s >= len) {
            cond = false;
        }
    }
    return ret;
}

int main() {
    string input, n1, n2;
    // vector<vector<int>> v;
    int x;
    m['0'] = "0000";
    m['1'] = "0001";
    m['2'] = "0010";
    m['3'] = "0011";
    m['4'] = "0100";
    m['5'] = "0101";
    m['6'] = "0110";
    m['7'] = "0111";
    m['8'] = "1000";
    m['9'] = "1001";
    m['A'] = "1010";
    m['B'] = "1011";
    m['C'] = "1100";
    m['D'] = "1101";
    m['E'] = "1110";
    m['F'] = "1111";
    getline(cin, input);
    input = convertToBin(input);
    // while (getline(cin, input)) {
    // stringstream ss (input);
    // }
    // cout << convertToDec("1101") << endl;
    cout << input << endl;
    // int v = convertToDec(input.substr(i, 3));
    i += 3;
    // version += v;
    long curr = operatorPacket(input);
    cout << curr << endl;
}