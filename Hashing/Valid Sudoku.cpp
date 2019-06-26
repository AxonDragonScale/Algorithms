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
