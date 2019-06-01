// https://www.interviewbit.com/problems/nqueens/
// This solution is good but also check out interviewbit solution

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

void printBoard(vector<string> &board) {
    for (string row : board) {
        cout << row << endl;
    }
}

bool isSafe(vector<pair<int, int>> &queens, int r, int c) {
    for (pair<int, int> queen : queens) {
        if (queen.first == r) return false;
        if (queen.second == c) return false;
        if (queen.first - queen.second == r - c) return false;
        if (queen.first + queen.second == r + c) return false;
    }

    return true;
}

void iterateOverBoard(vector<string> &board, int r, int c, vector<pair<int, int>> &queens,
                      vector<vector<string>> &ans) {
    int n = board.size();

    if (isSafe(queens, r, c)) {
        queens.push_back({r, c});
        board[r][c] = 'Q';

        if (queens.size() == n) {
            ans.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                iterateOverBoard(board, r + 1, i, queens, ans);
            }
        }

        board[r][c] = '.';
        queens.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<pair<int, int>> queens;

    for (int i = 0; i < n; i++) {
        iterateOverBoard(board, 0, i, queens, ans);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);

    for (vector<string> b : ans) {
        printBoard(b);
        cout << endl;
    }

    return 0;
}
