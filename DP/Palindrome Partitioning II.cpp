// https://www.interviewbit.com/problems/palindrome-partitioning-ii/
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int Solution::minCut(string s) {
    int n = s.size();

    vector<int> dp(n, 100000000);  // dp[i] is min cuts needed for s[0..i] + 1 (+1 because we make cut at the end)
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (isPalindrome(s, j, i)) {
                dp[i] = min(dp[i], 1 + (j > 0 ? dp[j - 1] : 0));
            }
        }
    }

    return dp[n - 1] - 1;
}
