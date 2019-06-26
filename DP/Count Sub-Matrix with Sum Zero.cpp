// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

// read solution approach for explanation -> good

int Solution::solve(vector<vector<int>> &mat) {
    int r = mat.size();
    if (r == 0) return 0;
    int c = mat[0].size();
    if (c == 0) return 0;

    vector<vector<int>> dp(r, vector<int>(c));  // stores prefix sums
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dp[i][j] = mat[i][j];
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int r1 = 0; r1 < r; r1++) {
        for (int r2 = r1; r2 < r; r2++) {
            unordered_map<int, int> count;
            count[0] = 1;  // count of 0 should be 1, so that any 0 sum submatrix is counted

            for (int j = 0; j < c; j++) {
                // sum is for submatrix between r1 and r2 with column 0 to j
                // so now its like 1-D, iterate on columns and check for same sum
                int sum = dp[r2][j] - (r1 > 0 ? dp[r1 - 1][j] : 0);

                // count > 0 if we got same sum before, if we got sum x times before, we can make x new 0-sum subarrays
                ans += count[sum];
                count[sum]++;
            }
        }
    }

    return ans;
}
