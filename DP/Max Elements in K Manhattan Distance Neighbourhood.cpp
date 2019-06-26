// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

vector<vector<int>> Solution::solve(int k, vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>> dp = mat;  // for k = 0, answer is the matrix itself
    vector<vector<int>> ans = dp;

    for (int dist = 1; dist <= k; dist++) {  // for dist iteration, dp has answer of dist-1 manhattan distance
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int cur = dp[i][j];

                if (i > 0) cur = max(cur, dp[i - 1][j]);      // expand ranges by 1, left
                if (i < r - 1) cur = max(cur, dp[i + 1][j]);  // right
                if (j > 0) cur = max(cur, dp[i][j - 1]);      // up
                if (j < c - 1) cur = max(cur, dp[i][j + 1]);  // down

                ans[i][j] = cur;
            }
        }

        dp = ans;
    }

    return ans;
}