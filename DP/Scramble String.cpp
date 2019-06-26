// http://n00tc0d3r.blogspot.com/2013/05/scramble-string.html
// https://www.interviewbit.com/problems/scramble-string/

// Given two strings a and b of the same length, determine if b is a scrambled string of a. Return 0/1 for this problem.

// Correct but WTF, why?, how? - http://n00tc0d3r.blogspot.com/2013/05/scramble-string.html
int Solution::isScramble(const string a, const string b) {
    int len = a.size();
    if (a == b) return 1;

    vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len, false)));
    // dp[i][j][l] is true if b[j..j+l] is a scrambled string of a[i..i+l], i and j are starting indices, l+1 is length

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            dp[i][j][0] = (a[i] == b[j]);
        }
    }

    for (int l = 1; l < len; l++) {
        for (int i = 0; i < len - l; i++) {
            for (int j = 0; j < len - l; j++) {
                // split into [0..n] and [n+1..l]
                for (int n = 0; n < l; n++) {
                    if ((dp[i][j][n] && dp[i + n + 1][j + n + 1][l - n - 1]) ||
                        (dp[i][j + l - n][n] && dp[i + n + 1][j][l - n - 1])) {
                        dp[i][j][l] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][0][len - 1];
}