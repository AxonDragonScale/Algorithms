
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

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
    int n, length;
    cin >> n;

    vector<int> prices(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];  // price[i] is the price of rod of lenght i
    }
    cin >> length;

    vector<int> dp(length + 1);  // dp[i] is the max value of rod of length i
    dp[0] = 0;

    for (int i = 1; i <= length; i++) {
        int temp = INT_MIN;

        for (int j = 1; j <= n && j <= i; j++) {
            temp = max(temp, prices[j] + dp[i - j]);  // j is cut out of rod and i - j is remaining length
        }
        dp[i] = temp;
    }

    cout << dp[n] << endl;

    return 0;
}