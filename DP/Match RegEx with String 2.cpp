// https://www.interviewbit.com/problems/regular-expression-ii/

// Implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// Examples -
// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "a*") → 1
// isMatch("aa", ".*") → 1
// isMatch("ab", ".*") → 1
// isMatch("aab", "c*a*b") → 1

int Solution::isMatch(const string s, const string p) {
    int sLen = s.size(), pLen = p.size();
    if (pLen == 0) {
        if (sLen == 0)
            return 1;
        else
            return 0;
    }

    vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
    dp[0][0] = true;  // empty pattern matches empty string
    for (int j = 2; j <= pLen; j++) {
        // empty string is matched by .*.* or .*.*.* or a*a* // dp[0][1] is still false as * means nothing
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    }
    // the base case of pLen = 0 and sLen > 0 is false by initialization

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (j >= 2) {
                    dp[i][j] = dp[i][j - 2];  // taking (prev*) as empty
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }  // else false
        }
    }

    return dp[sLen][pLen];
}
