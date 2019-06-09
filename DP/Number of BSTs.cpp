// https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

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

// Bottom Up
int numBST(int n) {
    if (n <= 1) return 1;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {      // i is the number of elements/nodes
        for (int j = 1; j <= i; j++) {  // if jth element is the root, left subtree has j-1 and right has i-j elements
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

// My Sol
int util(int n, vector<int> &dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];

    dp[n] = 0;
    for (int i = 1; i <= n; i++) {
        dp[n] += util(i - 1, dp) * util(n - i, dp);
    }

    return dp[n];
}

int numBST(int n) {
    vector<int> dp(n + 1, -1);
    return util(n, dp);
}

int main() {
    int n;
    cin >> n;

    cout << numBST(n) << endl;

    return 0;
}
