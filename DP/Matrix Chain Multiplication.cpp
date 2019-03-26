
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

int main() {
    int n;  // for n-1 matrices we will have n dimensions
    cin >> n;

    deque<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    deque<deque<int> > dp(n, deque<int>(n, INT_MAX));
    // dp[i][j] stores cost of product of matrices A[i]*A[i+1]...A[j]
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;  // no cost if there is only one matrix
    }

    for (int l = 2; l < n; l++) {
        // l is the chain length (need to find smaller chains before larger so we can't directly iterate over i and j)
        for (int i = 1; i < n - l + 1; i++) {  // max i should be n-1 so, n-l+1
            int j = i + l - 1;
            // dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }

    cout << dp[1][n - 1] << endl;

    return 0;
}
