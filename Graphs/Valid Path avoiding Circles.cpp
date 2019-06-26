// https://www.interviewbit.com/problems/valid-path/

// There is a rectangle with left bottom as (0, 0) and right up as (r, c). There are N circles such that their centers
// are inside the rectangle. Radius of each circle is 'radius'. Now we need to find out if it is possible that we can
// move from (0, 0) to (r, c) without touching any circle. Note : We can move from any cell to any of its 8 adjecent
// neighbours and we cannot move outside the boundary of the rectangle at any point of time.

vector<int> addX = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> addY = {-1, 0, 1, -1, 1, -1, 0, 1};

int sq(int n) { return n * n; }

bool isValid(int i, int j, int r, int c, vector<int> &x, vector<int> &y, int radius) {
    if (i < 0 || i > r || j < 0 || j > c) return false;

    for (int k = 0; k < x.size(); k++) {
        if (sq(x[k] - i) + sq(y[k] - j) <= sq(radius)) return false;
    }

    return true;
}

string Solution::solve(int r, int c, int n, int radius, vector<int> &x, vector<int> &y) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(r + 1, vector<bool>(c + 1, false));

    if (isValid(0, 0, r, c, x, y, radius)) {
        q.push({0, 0});
        vis[0][0] = true;
    }

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i == r && j == c) {
            return "YES";
        }

        for (int k = 0; k < 8; k++) {
            int nx = i + addX[k], ny = j + addY[k];
            if (isValid(nx, ny, r, c, x, y, radius) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return "NO";
}
