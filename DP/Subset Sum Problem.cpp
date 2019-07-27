// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal
// to given sum.

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

// only uses O(sum) space
bool subsetSumBetter(vi &set, int sum) {
    int n = set.size();

    vector<bool> dp(sum + 1), prev(sum + 1, false);
    prev[0] = true;  // for empty set we can make 0, but nothing else

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j)
                dp[j] = prev[j];
            else if (set[i - 1] <= j)
                dp[j] = prev[j] || prev[j - set[i - 1]];
        }

        prev = dp;
    }

    return dp[sum];
}

// uses O(sum * n) space
bool subsetSum(vi &set, int sum) {
    int n = set.size();

    // dp[i][j] is true if we can make a subset with sum j only considering the first i elements of set
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = true;     // we can make zero sum from any set
    for (int j = 1; j <= sum; j++) dp[0][j] = false;  // we cant make a non zero sum with zero elements

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];  // dont include ith element (at index i-1)
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];  // include ith element
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vi set(n);
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << subsetSumBetter(set, sum);

    return 0;
}
