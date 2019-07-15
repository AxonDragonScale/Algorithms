// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/#include <algorithm>

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

int minInsertionToMakePalindrome(string &s) {
    int n = s.size();

    vector<vi> dp(n, vi(n, 0));
    // dp[i][j] is the number of insertions needed to make s[i..j] a palindrome

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;

    cout << minInsertionToMakePalindrome(s);

    return 0;
}
