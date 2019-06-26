// https://www.interviewbit.com/problems/ways-to-decode/

int Solution::numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n, 0);  // dp[i] stores ways to decode s[0..i]
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] > '0') dp[i] += dp[i - 1];  // s[i] represents a letter

        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {  // s[i-1] and s[i] represent a letter
            dp[i] += (i - 2 >= 0) ? dp[i - 2] : 1;
        }
    }

    return dp[n - 1];
}
