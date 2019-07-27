// https://www.interviewbit.com/problems/sudoku/

bool isValid(vector<vector<char>> &mat, char val, int r, int c) {
    for (int i = 0; i < 9; i++) {
        if (mat[r][i] == val) return false;  // same val shouldn't be present in the row
        if (mat[i][c] == val) return false;  // same val shouldn't be present in the col
    }

    for (int i = 2; i <= 8; i += 3) {  // change r and c to the center of its sub-matrix
        if (r >= i - 2 && r <= i) r = i - 1;
        if (c >= i - 2 && c <= i) c = i - 1;
    }

    if (mat[r - 1][c - 1] == val || mat[r - 1][c] == val || mat[r - 1][c + 1] == val || mat[r][c - 1] == val ||
        mat[r][c] == val || mat[r][c + 1] == val || mat[r + 1][c - 1] == val || mat[r + 1][c] == val ||
        mat[r + 1][c + 1] == val)
        return false;  // same val shouldn't be present in the same sub-matrix

    return true;
}

bool util(vector<vector<char>> &mat, int r, int c) {
    if (r == 8 && c == 9) return true;       // if it reaches the block after the last, complete
    if (c == 9) return util(mat, r + 1, 0);  // go to next row

    if (mat[r][c] != '.') {
        return util(mat, r, c + 1);
    }

    for (char i = '1'; i <= '9'; i++) {
        if (isValid(mat, i, r, c)) {
            mat[r][c] = i;
            if (util(mat, r, c + 1)) {
                return true;
            }
            mat[r][c] = '.';
        }
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char>> &mat) {
    int n = mat.size();
    util(mat, 0, 0);
}
