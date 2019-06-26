// https://www.interviewbit.com/problems/count-permutations-of-bst/

using lli = long long int;
int mod = 1e9 + 7;

lli util(vector<vector<lli>> &dp, vector<vector<lli>> &C, int n, int h) {
    if (n <= 1) return (h == 0);
    if (h < 0) return 0;

    lli &ans = dp[n][h];
    if (ans != -1) return ans;

    ans = 0;
    int l, r;
    for (int i = 1; i <= n; i++) {
        l = i - 1;
        r = n - i;

        lli leftWays = 0, rightWays = 0;
        for (int height = 0; height <= h - 2; height++) {
            leftWays = (leftWays + util(dp, C, l, height)) % mod;
            rightWays = (rightWays + util(dp, C, r, height)) % mod;
        }

        lli temp = (leftWays * util(dp, C, r, h - 1)) % mod;
        temp = (temp + (rightWays * util(dp, C, l, h - 1)) % mod) % mod;
        temp = (temp + (util(dp, C, l, h - 1) * util(dp, C, r, h - 1)) % mod) % mod;
        temp = (temp * C[l + r][r]) % mod;

        ans = (ans + temp) % mod;
    }

    return ans;
}

int Solution::cntPermBST(int n, int h) {
    vector<vector<lli>> dp(n + 1, vector<lli>(h + 1, -1));

    vector<vector<lli>> C(n + 1, vector<lli>(n + 1));
    C[0][0] = 1;
    for (int k = 1; k <= n; k++) {
        C[k][0] = 1;
        C[k][k] = 1;
        for (int r = 1; r < k; r++) {
            C[k][r] = (C[k - 1][r - 1] + C[k - 1][r]) % mod;
        }
    }

    return util(dp, C, n, h);
}
