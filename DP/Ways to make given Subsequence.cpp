// https://www.interviewbit.com/problems/distinct-subsequences/

// Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the
// sequence T.

int util(vector<vector<int>> &dp, string &s, int sIdx, string &t, int tIdx) {
    if (sIdx < tIdx) return 0;  // if s is smaller, we cant make t from it. Also stops recursion when sIdx becomes -1.
    if (dp[sIdx][tIdx] != -1) return dp[sIdx][tIdx];

    int ans = 0;
    if (tIdx == 0 && s[sIdx] == t[tIdx]) {
        ans += 1;  // dont return, a smaller sIdx could also be same t[tIdx], so recur for tIdx-1
    } else if (s[sIdx] == t[tIdx]) {
        ans += util(dp, s, sIdx - 1, t, tIdx - 1);
    }

    ans += util(dp, s, sIdx - 1, t, tIdx);
    return dp[sIdx][tIdx] = ans;
}

int Solution::numDistinct(string s, string t) {
    int sLen = s.size(), tLen = t.size();
    vector<vector<int>> dp(sLen, vector<int>(tLen, -1));  // dp[i][j] stores answer for s[0..i] and t[0..j]
    return util(dp, s, sLen - 1, t, tLen - 1);
}

// InterviewBit Solution
/**
 * Solution (DP):
 * We keep a m*n matrix and scanning through string S, while
 * m = T.length() + 1 and n = S.length() + 1
 * and each cell in matrix Path[i][j] means the number of distinct subsequences of
 * T.substr(1...i) in S(1...j)
 *
 * Path[i][j] = Path[i][j-1]            (discard S[j])
 *              +     Path[i-1][j-1]    (S[j] == T[i] and we are going to use S[j])
 *                 or 0                 (S[j] != T[i] so we could not use S[j])
 * while Path[0][j] = 1 and Path[i][0] = 0.
 */
int numDistinct(string S, string T) {
    int tLen = T.length();
    int sLen = S.length();
    if (tLen > sLen) return 0;  // impossible for subsequence
    vector<vector<int>> path(tLen + 1, vector<int>(sLen + 1, 0));
    for (int k = 0; k <= sLen; k++) path[0][k] = 1;  // initialization

    for (int j = 1; j <= sLen; j++) {
        for (int i = 1; i <= tLen; i++) {
            path[i][j] = path[i][j - 1] + (T[i - 1] == S[j - 1] ? path[i - 1][j - 1] : 0);
        }
    }

    return path[tLen][sLen];
}