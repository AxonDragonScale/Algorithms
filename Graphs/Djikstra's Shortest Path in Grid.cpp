// https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/

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

struct Cell {
    int dist;
    int row;
    int col;
};

struct Comp {
    bool operator()(const Cell &a, const Cell &b) {
        if (a.dist == b.dist) {
            if (a.row != b.row)
                return a.row > b.row;
            else
                return a.col > b.col;
        }
        return a.dist > b.dist;
    }
};

int main() {
    int r, c;
    cin >> r >> c;

    vector<vi> grid(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vi> dist(r, vi(c, INT_MAX));
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    vi dr = {-1, 1, 0, 0};
    vi dc = {0, 0, -1, 1};

    priority_queue<Cell, vector<Cell>, Comp> minHeap;

    dist[0][0] = 0;
    minHeap.push({0, 0, 0});
    vis[0][0] = true;

    while (!minHeap.empty()) {
        Cell cur = minHeap.top();
        minHeap.pop();

        for (int i = 0; i < 4; i++) {
            int row = cur.row + dr[i];
            int col = cur.col + dc[i];
            if (row < 0 || row >= r || col < 0 || col >= c) continue;

            if (dist[row][col] > dist[cur.row][cur.col] + grid[row][col]) {
                dist[row][col] = dist[cur.row][cur.col] + grid[row][col];
                minHeap.push({dist[row][col], row, col});
            }
        }
    }

    cout << dist[r - 1][c - 1] << endl;

    return 0;
}
