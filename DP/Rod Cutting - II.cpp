// https://www.interviewbit.com/problems/rod-cutting/

// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak
// points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all
// these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods.
// Cost of making a cut is the length of the sub-rod in which you are making a cut. Your aim is to minimise this cost.
// Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost,
// return the lexicographically smallest.

// TODO : solution 1 on interviewbit

// Ignore this Solution
void util(vector<int> &ans, vector<vector<int>> &dp, vector<int> &arr, int i, int j) {
    if (i + 1 == j) return;

    for (int k = i + 1; k < j; k++) {
        if (dp[i][k] + dp[k][j] + arr[j] - arr[i] == dp[i][j]) {
            ans.push_back(arr[k]);
            util(ans, dp, arr, i, k);
            util(ans, dp, arr, k, j);
            return;
        }
    }
}

vector<int> Solution::rodCut(int n, vector<int> &arr) {
    arr.insert(arr.begin(), 0);
    arr.push_back(n);
    sort(arr.begin(), arr.end());

    int len = arr.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int l = 2; l <= len; l++) {
        for (int i = 0; i + l - 1 < len; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[j] - arr[i]);
            }
        }
    }

    vector<int> ans;
    util(ans, dp, arr, 0, len - 1);
    return ans;
}