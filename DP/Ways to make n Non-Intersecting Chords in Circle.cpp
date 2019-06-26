// https://www.geeksforgeeks.org/count-ways-divide-circle-using-n-non-intersecting-chords/
// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

using lli = long long int;

int Solution::chordCnt(int n) {
    int mod = 1e9 + 7;

    vector<lli> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {                // i chords
        for (int pnt = 0; pnt <= i - 1; pnt++) {  // i chords is 0 to i-1
            dp[i] = (dp[i] + (dp[pnt] * dp[(i - 1) - pnt]) % mod) % mod;
            // If we choose chord pnt+1, then it divides circle into 2 sets of pnt chords and (i-1)-pnt chords
        }
    }

    return dp[n];
}

using lli = long long int;

int Solution::chordCnt(int n) {
    int mod = 1e9 + 7;

    n = n * 2;
    vector<lli> dp(n + 1, 0);
    dp[0] = 1;
    dp[2] = 1;

    for (int i = 4; i <= n; i += 2) {                // i points
        for (int pnt = 0; pnt <= i - 2; pnt += 2) {  // i points is 0 to i-2
            dp[i] = (dp[i] + (dp[pnt] * dp[(i - 2) - pnt]) % mod) % mod;
        }
    }

    return dp[n];
}