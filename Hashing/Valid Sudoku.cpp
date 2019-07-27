// https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &mat) {
    for (int i = 0; i < 9; i++) {
        vector<bool> r(9, false), c(9, false);
        for (int j = 0; j < 9; j++) {
            if (mat[i][j] != '.') {
                if (!r[mat[i][j] - '1'])
                    r[mat[i][j] - '1'] = true;
                else
                    return 0;
            }
            if (mat[j][i] != '.') {
                if (!c[mat[j][i] - '1'])
                    c[mat[j][i] - '1'] = true;
                else
                    return 0;
            }
        }
    }

    for (int i = 0; i <= 6; i += 3) {
        for (int j = 0; j <= 6; j += 3) {
            vector<bool> vis(9, false);
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (mat[r][c] != '.') {
                        if (!vis[mat[r][c] - '1'])
                            vis[mat[r][c] - '1'] = true;
                        else
                            return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// https://leetcode.com/problems/valid-sudoku/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

int main() {
    deque<deque<char> > board(9, deque<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    deque<short> row(9);  // 9 rows, for each row, bit i represents if row has i+1
    deque<short> col(9);
    deque<short> block(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int idx = 1 << (board[i][j] - '0');

                if (row[i] & idx || col[j] & idx || block[(i / 3) * 3 + j / 3] & idx) {
                    cout << "Not valid" << endl;
                    return 0;
                } else {
                    row[i] |= idx;
                    col[j] |= idx;
                    block[(i / 3) * 3 + j / 3] |= idx;
                }
            }
        }
    }

    cout << "Valid" << endl;

    return 0;
}
