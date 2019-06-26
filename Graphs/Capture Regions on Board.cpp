// https://www.interviewbit.com/problems/capture-regions-on-board/
// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

// https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/  ->  concept kinda taken from here

// The main concept is that any O that is connect to the boundary is not captured
void floodFill(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
    if (grid[i][j] != '*') return;

    grid[i][j] = 'O';
    floodFill(grid, i - 1, j);
    floodFill(grid, i + 1, j);
    floodFill(grid, i, j - 1);
    floodFill(grid, i, j + 1);
}

void Solution::solve(vector<vector<char>> &grid) {
    int r = grid.size();
    int c = grid[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') grid[i][j] = '*';
        }
    }

    for (int i = 0; i < r; i++) {
        if (grid[i][0] == '*') floodFill(grid, i, 0);          // left edge
        if (grid[i][c - 1] == '*') floodFill(grid, i, c - 1);  // right edge
    }

    for (int j = 0; j < c; j++) {
        if (grid[0][j] == '*') floodFill(grid, 0, j);          // top edge
        if (grid[r - 1][j] == '*') floodFill(grid, r - 1, j);  // bottom edge
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '*') grid[i][j] = 'X';
        }
    }
}