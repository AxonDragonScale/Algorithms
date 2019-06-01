// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &arr) {
    int n = arr.size();

    vector<int> dp(n, 0);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int maxJump = arr[i];
        for (int j = i + 1; j <= i + maxJump; j++) {
            if (dp[j] == 1) {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[0];
}

// We dont need to store dp, just the lowest reachable index
int Solution::canJump(vector<int> &arr) {
    int n = arr.size();

    int minIndex = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= minIndex) {
            minIndex = i;
        }
    }

    if (minIndex == 0)
        return 1;
    else
        return 0;
}
