
// https://www.geeksforgeeks.org/coin-change-dp-7/
// https://practice.geeksforgeeks.org/problems/coin-change/0

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl

using namespace std;

void coinChange(vector<int> &coins, int k) {
    int n = coins.size();
    vector<int> dp(k + 1, 0);

    dp[0] = 1;  // only one way to make zero sum

    for (int c = 0; c < n; c++) {                    // iterate over all coins
        for (int sum = coins[c]; sum <= k; sum++) {  // the coin can be used in sums >= it
            dp[sum] += dp[sum - coins[c]];
        }
    }

    cout << dp[k] << endl;
}

// less efficient
void coinChange(vector<int> &coins, int k) {
    int n = coins.size();

    // k+1 coz we consider the case when sum is 0
    vector<vector<int>> dp(k + 1, vector<int>(n));

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;  // there is only one way to make 0, no matter how many coins we use
    }

    for (int sum = 1; sum <= k; sum++) {
        for (int c = 0; c < n; c++) {
            // sum is the sum and c is the no of coins used
            int cthCoinIncluded = sum - coins[c] >= 0 ? dp[sum - coins[c]][c] : 0;
            int cthCoinNotIncluded = c >= 1 ? dp[sum][c - 1] : 0;
            // if c is 0, 0 ways
            dp[sum][c] = cthCoinIncluded + cthCoinNotIncluded;
        }
    }

    cout << dp[k][n - 1] << endl;
}

int main() {
    int t, k, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> coins;
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        cin >> k;

        coinChange(coins, k);
    }

    return 0;
}