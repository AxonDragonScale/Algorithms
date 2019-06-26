// https://www.interviewbit.com/problems/arrange-ii/
// http://sahityapatel.blogspot.com/2017/08/interviewbit-dynamic-programming.html

int Solution::arrange(string horses, int stables) {
    int n = horses.size();
    if (n < stables) return -1;
    if (n == stables) return 0;

    vector<vector<int>> dp(n, vector<int>(stables + 1));
    int w = 0, b = 0;
    for (int i = 0; i < n; i++) {  // base case for 1 stable
        if (horses[i] == 'W')
            w++;
        else
            b++;

        dp[i][1] = b * w;
    }

    for (int s = 2; s <= stables; s++) {
        for (int i = 0; i < n; i++) {
            dp[i][s] = 1e9;

            int w = 0, b = 0;
            for (int k = i; k > 0; k--) {
                if (horses[k] == 'W')
                    w++;
                else
                    b++;

                dp[i][s] = min(dp[i][s], dp[k - 1][s - 1] + w * b);
            }
        }
    }

    return dp[n - 1][stables];
}
