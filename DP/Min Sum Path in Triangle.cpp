// https://www.interviewbit.com/problems/min-sum-path-in-triangle/
// https://www.geeksforgeeks.org/minimum-sum-path-triangle/

// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row
// below. For example triangle is like -
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]

int Solution::minimumTotal(vector<vector<int>> &t) {
    int n = t.size();

    vector<int> dp(n);  // triangle has n rows, so last row has n items
    for (int i = 0; i < t[n - 1].size(); i++) {
        dp[i] = t[n - 1][i];
    }

    // for iteration i, dp will have min sum for row i+1 from each element of i+1 and rest dont matter anymore
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < t[i].size(); j++) {
            dp[j] = t[i][j] + min(dp[j], dp[j + 1]);  // j can only go to j and j+1 of next row
        }
    }

    return dp[0];
}
