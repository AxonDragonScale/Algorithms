// https://www.geeksforgeeks.org/edit-distance-dp-5/
// https://practice.geeksforgeeks.org/problems/edit-distance/0

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int minEditDistance(string a, string b) {
    int aLen = a.size();
    int bLen = b.size();

    vector<vector<int>> dp(aLen + 1, vector<int>(bLen + 1));
    // dp[i][j] stores answer for a[0..i-1] and b[0..j-1] i.e i letters of a and j letters of b

    // if j = 0, then we have to delete all i letters, so cost is i
    for (int i = 0; i <= aLen; i++) {
        dp[i][0] = i;
    }

    // if i = 0, then we have to add all j letters, so cost is j
    for (int j = 0; j <= bLen; j++) {
        dp[0][j] = j;
    }

    // Iterate over lengths
    for (int i = 1; i <= aLen; i++) {
        for (int j = 1; j <= bLen; j++) {
            if (a[i - 1] == b[j - 1]) {  // if letters are same no cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {  // cost is 1 + min(adding, deleting and replacing)
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[aLen][bLen];
}

int t, n1, n2;
string s1, s2;
int dp[100][100];

void editDistance() {
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0) {
                // if 1st string is empty, add all elements in 2nd string
                dp[i][j] = j;
            } else if (j == 0) {
                // if 2nd string is empty, remove all from 1st string
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                // if same, no cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // otherwise 1 + min cost(add, remove, replace)
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    cout << dp[n1][n2] << endl;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n1 >> n2;
        cin >> s1 >> s2;

        editDistance();
    }

    return 0;
}