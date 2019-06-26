// https://www.interviewbit.com/problems/knight-on-chess-board/
// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

// Given any source point and destination point on a chess board, we need to find min moves for Knight to recah the
// destination. Indexing is 1-based.

vector<int> addR = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> addC = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int i, int j, int r, int c) { return i >= 1 && i <= r && j >= 1 && j <= c; }

struct Item {
    int moves;
    int r;
    int c;
};

struct comp {
    bool operator()(const Item &a, const Item &b) { return a.moves > b.moves; }
};

int Solution::knight(int r, int c, int sr, int sc, int dr, int dc) {
    vector<vector<bool>> vis(r + 1, vector<bool>(c + 1, false));
    vector<vector<int>> moves(r + 1, vector<int>(c + 1, INT_MAX));
    priority_queue<Item, vector<Item>, comp> minHeap;

    minHeap.push({0, sr, sc});
    moves[sr][sc] = 0;

    while (!minHeap.empty()) {
        Item t = minHeap.top();
        minHeap.pop();
        vis[t.r][t.c] = true;

        for (int i = 0; i < 8; i++) {
            int x = t.r + addR[i], y = t.c + addC[i];
            if (isValid(x, y, r, c) && !vis[x][y] && moves[x][y] > 1 + moves[t.r][t.c]) {
                moves[x][y] = 1 + moves[t.r][t.c];
                minHeap.push({moves[x][y], x, y});
            }
        }
    }

    if (moves[dr][dc] == INT_MAX) return -1;
    return moves[dr][dc];
}
