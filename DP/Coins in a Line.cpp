// https://www.interviewbit.com/problems/coins-in-a-line/
// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

// There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the
// line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.
// Write a program which computes the maximum amount of money you can win.

// method 1 - https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-2/
int maxCoinsUtil(vector<int> &arr, vector<vector<int>> &dp, int l, int r, int sum) {
    if (l + 1 == r) return max(arr[l], arr[r]);
    if (dp[l][r] != -1) return dp[l][r];

    // opponent will take max in his turn, so we get total - opponent
    int chooseL = sum - maxCoinsUtil(arr, dp, l + 1, r, sum - arr[l]);
    int chooseR = sum - maxCoinsUtil(arr, dp, l, r - 1, sum - arr[r]);

    return dp[i][j] = max(chooseL, chooseR);
}

int maxCoins(vector<int> &arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return maxCoinsUtil(arr, dp, 0, n - 1, sum);
}

// method 2
int maxcoinUtil(vector<int> &A, vector<vector<int>> &dp, int start, int end) {
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    if ((start == end || start + 1 == end) {
        return max(A[start], A[end]);
    }

    int option1 = maxcoinUtil(A, dp, start + 2, end);
    int option2 = maxcoinUtil(A, dp, start + 1, end - 1);
    int option3 = maxcoinUtil(A, dp, start, end - 2);

    // we take min bcoz the other player also plays optimally
    int chooseStart = A[start] + min(option1, option2);
    // we choose start and other player chooses start+1 or end whichever gives him max
    int chooseEnd = A[end] + min(option2, option3);
    // we choose end and other player chooses start ot end-1 whichever gives him max

    dp[start][end] = max(chooseStart, chooseEnd);
    return dp[start][end];
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));  // dp[i][j] stores max sum for coins in i to j

    return maxcoinUtil(A, dp, 0, n - 1);
}
