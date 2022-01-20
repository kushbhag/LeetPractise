// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Medium



#include<vector>

using namespace std;
// O(mn) create and O(m) sum
class NumMatrix {
    vector<vector<int>> mem;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        mem = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                mem[i][j+1] = mem[i][j] + matrix[i][j];
                //cout <<mem[i][j+1] << ' ';
            }
            //cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            // cout << col1 << ' ' << col2 << endl;
            sum += (mem[i][col2+1] - mem[i][col1]);
            // cout << mem[i][col2+1] - mem[i][col1] << endl;
        }
        return sum;
    }
};

// O(mn) space and O(1) sum
class NumMatrix {
    vector<vector<int>> mem;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        mem = vector<vector<int>> (matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            int currSum = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                mem[i+1][j+1] = currSum + mem[i][j+1] + matrix[i][j];
                currSum += matrix[i][j];
                //cout << mem[i+1][j+1] << ' ';
            }
            //cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mem[row1][col1] + mem[row2+1][col2+1] - mem[row1][col2+1] - mem[row2+1][col1];
    }
};
