// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

// Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid
// number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

int util(int n, int sum, bool f, vector<vector<int>> &dp) {
    if (n == 1) {
        if (sum >= 0 && sum <= 9)
            return 1;
        else
            return 0;
    }

    if (sum < 0) return 0;

    if (dp[n][sum] != -1) return dp[n][sum];

    int count = 0;
    int i = 1;
    if (f) i = 0;
    for (; i < 10; i++) {
        count = (count + util(n - 1, sum - i, true, dp)) % 1000000007;
    }

    return dp[n][sum] = count;
}

int Solution::solve(int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return util(n, sum, false, dp);  // false cause first digit cant be 0
}
