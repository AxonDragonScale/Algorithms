// https://www.interviewbit.com/problems/word-search-board/
// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
// or vertically neighboring. The cell itself does not count as an adjacent cell. The same letter cell may be used more
// than once.

vector<int> addX = {-1, 1, 0, 0};
vector<int> addY = {0, 0, -1, 1};

bool util(vector<string> &grid, string word, int i, int j, int idx) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
    if (idx == word.size() - 1) {
        return word[idx] == grid[i][j];
    }

    if (grid[i][j] != word[idx]) return false;
    for (int k = 0; k < 4; k++) {
        if (util(grid, word, i + addX[k], j + addY[k], idx + 1)) return true;
    }

    return false;
}

int Solution::exist(vector<string> &grid, string word) {
    int r = grid.size(), c = grid[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == word[0]) {
                if (util(grid, word, i, j, 0)) return 1;
            }
        }
    }

    return 0;
}
