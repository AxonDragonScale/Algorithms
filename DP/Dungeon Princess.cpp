// https://www.interviewbit.com/problems/dungeon-princess/
// https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

// Read Question
// Start from bottom right with 1 HP, for each cell add the HP losses and subract the HP bonuses.
// We need atleast this much HP to reach dest from this cell, if we need <= 0 HP to reach dest from cell change it to 1.
// (Because HP needed is atleast 1 anywhere)

int Solution::calculateMinimumHP(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (i == r - 1 && j == c - 1)
                dp[i][j] = 1;
            else if (i == r - 1)
                dp[i][j] = dp[i][j + 1];
            else if (j == c - 1)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);

            dp[i][j] = max(dp[i][j] - grid[i][j], 1);
        }
    }

    return dp[0][0];
}