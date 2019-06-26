// https://www.interviewbit.com/problems/interleaving-strings/
// Given a, b, c, find whether c is formed by the interleaving of a and b.

using vi = vector<int>;

int util(vector<vector<vi>> &dp, string a, string b, string c, int aLen, int bLen, int cLen) {
    if (aLen == 0 && bLen == 0 && cLen == 0)
        return 1;
    else if (aLen == 0 && bLen == 0)
        return 0;

    if (aLen + bLen != cLen) return 0;
    if (dp[aLen][bLen][cLen] != -1) return dp[aLen][bLen][cLen];

    if (aLen >= 1 && a[aLen - 1] == c[cLen - 1]) {
        if (util(dp, a, b, c, aLen - 1, bLen, cLen - 1)) return dp[aLen][bLen][cLen] = 1;
    }
    if (bLen >= 1 && b[bLen - 1] == c[cLen - 1]) {
        if (util(dp, a, b, c, aLen, bLen - 1, cLen - 1)) return dp[aLen][bLen][cLen] = 1;
    }

    int ans = 0;
    if (util(dp, a, b, c, aLen - 1, bLen, cLen) || util(dp, a, b, c, aLen, bLen - 1, cLen)) {
        ans = 1;
    }
    return dp[aLen][bLen][cLen] = ans;
}

int Solution::isInterleave(string a, string b, string c) {
    int aLen = a.size(), bLen = b.size(), cLen = c.size();
    vector<vector<vi>> dp(aLen + 1, vector<vi>(bLen + 1, vi(cLen + 1, -1)));

    return util(dp, a, b, c, aLen, bLen, cLen);
}
