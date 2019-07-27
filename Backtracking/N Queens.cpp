// Given an n*n chessboard, place n queens such that they cant attack each other
// CHECK geeksforgeeks algo

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

// basic iteration
void iterateOverBoard(deque<di> &board, int r, int c) {
    int n = board.size();
    if (c == n) {
        iterateOverBoard(board, r + 1, 0);
        return;
    }

    if (r == n) {
        return;
    }

    iterateOverBoard(board, r, c + 1);
}

int clash(deque<di> &board, iPair q1, iPair q2) {
    if (q1.ff == q2.ff) return 1;
    if (q1.ss == q2.ss) return 1;
    if (q1.ss - q1.ff == q2.ss - q2.ff) return 1;
    if (q1.ff + q1.ss == q2.ff + q2.ss) return 1;

    return 0;
}

int sol(deque<di> &board, deque<iPair> &queens, int r, int c) {
    int n = board.size();
    if (r == n) {
        if (queens.size() == n) {
            return 1;
        }
        return 0;
    }
    if (c == n) {
        return sol(board, queens, r + 1, 0);
    }

    int canPlace = 1;
    for (auto queen : queens) {
        if (clash(board, queen, {r, c})) {
            canPlace = 0;
            break;
        }
    }

    if (canPlace) {
        queens.push_back({r, c});
        if (sol(board, queens, r, c + 1)) {  // attempt with placing the queen
            return 1;
        }
        queens.pop_back();
    }

    return sol(board, queens, r, c + 1);  // attempt with not placing the queen
}

int main() {
    int n;
    cin >> n;

    deque<di> board(n, di(n, 0));
    deque<iPair> queens;

    sol(board, queens, 0, 0);

    for (auto queen : queens) {
        board[queen.ff][queen.ss] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
