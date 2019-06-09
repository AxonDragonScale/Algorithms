// https://www.interviewbit.com/problems/min-sum-path-in-matrix/
//  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
//  sum of all numbers along its path. You can only move either down or right at any point in time.

int Solution::minPathSum(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < r; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < c; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }

    return dp[r - 1][c - 1];
}