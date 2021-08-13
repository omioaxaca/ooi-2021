/*
 * Chessboard and Queens
 * https://cses.fi/problemset/task/1624
 */
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
 
bool queen_is_safe(vector<int>& chess, int col, int row) {
    for (int i = 0; i < col; ++i) {
        if (row == chess[i]) {
            return false; // same row
        }
        if (abs(col - i) == abs(row - chess[i]))  {
            return false; // same diagonal
        }
    }
 
    return true;
}
 
 
int count_ways(vector<int>& chess, vector<int>& reserved, uint c_col=0) {
    if (c_col == 8) {
        return 1;
    }
 
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (!queen_is_safe(chess, c_col, i) || reserved[i * 8 + c_col] == 3) {
            continue;
        }
 
        chess[c_col] = i;
        count += count_ways(chess, reserved, c_col+1);
        chess[c_col] = -1;
    }
 
    return count;
}
 
 
 
int main(int argc, char const *argv[]) {
    vector<int> chess(8, -1);
    vector<int> reserved(8*8, -1);
 
    string line;
 
    for (int i = 0; i < 8; i++){
        cin >> line;
        for (int j = 0; j < 8; j++) {
            if (line[j] == '*') {
                reserved[i * 8 + j] = 3;
            }
        }
    }
 
    cout << count_ways(chess, reserved) << "\n";
 
    return 0;
}