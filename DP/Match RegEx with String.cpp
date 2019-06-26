// https://www.interviewbit.com/problems/regular-expression-match/
// https://www.geeksforgeeks.org/wildcard-pattern-matching/

// Implement wildcard pattern matching with support for '?' and '*'.
//     '?' : Matches any single character.
//     '*' : Matches any sequence of characters (including the empty sequence).
// Examples -
// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "*") → 1
// isMatch("aa", "a*") → 1
// isMatch("ab", "?*") → 1
// isMatch("aab", "c*a*b") → 0

// s is the string, p is the pattern

int Solution::isMatch(const string s, const string p) {
    int sLen = s.size(), pLen = p.size();
    if (pLen == 0) {
        if (sLen == 0)
            return 1;
        else
            return 0;
    }

    vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
    dp[0][0] = true;                   // empty pattern matches empty string
    for (int j = 1; j <= pLen; j++) {  // empty string matches a pattern if it has only *s in it
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  // * matches matches a substring || * matches empty
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }  // else dp[i][j] remains false
        }
    }

    return dp[sLen][pLen];
}

int Solution::isMatch(const string s, const string p) {
    int sLen = s.size(), pLen = p.size();

    int starPos = -1, prevStart = 0;
    int i = 0, j = 0;
    while (i < sLen) {
        if (s[i] == p[j] || p[j] == '?') {
            i++;
            j++;
        } else if (p[j] == '*') {
            starPos = j;
            prevStart = i;
            j++;                     // * matches empty
        } else if (starPos != -1) {  // no match, so go back to starPos and include prevStart in *
            j = starPos;
            i = ++prevStart;
        } else {
            return false;
        }
    }

    while (j < pLen && p[j] == '*') j++;
    return j == pLen;
}