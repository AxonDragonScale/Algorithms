// https://www.interviewbit.com/problems/kingdom-war/

int Solution::solve(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int ans = INT_MIN;
    vector<vector<int>> dp(r, vector<int>(c));
    // as the strength increases as we go right or down, the ans sub matrix will always include bottom right
    // dp[i][j] is sum of sub matrix i,j to r-1,c-1

    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            dp[i][j] = mat[i][j];
            if (i + 1 < r) dp[i][j] += dp[i + 1][j];
            if (j + 1 < c) dp[i][j] += dp[i][j + 1];
            if (i + 1 < r && j + 1 < c) dp[i][j] -= dp[i + 1][j + 1];  // bcoz its repeated if we add both

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
