// https://www.geeksforgeeks.org/repeated-subsequence-length-2/
// https://www.interviewbit.com/problems/repeating-subsequence/

// Method 1 - O(n)
bool isPalindrome(string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int Solution::anytwo(string s) {
    int n = s.size();

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
        if (freq[c] > 2) return 1;  // If it occurs 3 or more times, then repeating subsequence
    }

    // Remove all non repeating characters as they cant be in repeating subsequence
    int i = 0, j = 0;
    while (j < n) {
        if (freq[s[j]] > 1)
            s[i++] = s[j++];
        else
            j++;
    }
    s.resize(i);
    n = i;

    // string will have 2 of all chars, if palindrome then cant be repeating subsequence
    if (isPalindrome(s)) return 0;
    return 1;
}

// Method 2
int lcs(string a, string b) {
    int aLen = a.size(), bLen = b.size();
    vector<vector<int>> dp(aLen + 1, vector<int>(bLen + 1, 0));
    // lcs[i][j] stores the length of LCS of a[0..i-1] and b[0..j-1]
    // i.e considering only first i and j elements of a and b or size is i and j
    // Initialize with 0 as base case, if length of any is 0, then lcs is 0;

    for (int i = 1; i <= aLen; i++) {
        for (int j = 1; j <= bLen; j++) {
            if (a[i - 1] == b[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[aLen][bLen];
}

int Solution::anytwo(string s) { return lcs(s, s) >= 2; }
