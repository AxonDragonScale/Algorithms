// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

// Given a binary matrix, find out the area of maximum size square sub-matrix with all 1s.

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

int maximalSquare(vector<vi> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    vector<vi> dp(r, vi(c));
    for (int i = 0; i < r; i++) {
        dp[i][0] = mat[i][0];
    }
    for (int j = 0; j < c; j++) {
        dp[0][j] = mat[0][j];
    }

    int mx = 0, maxR, maxC;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (mat[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] > mx) {
                mx = dp[i][j];
                maxR = i;
                maxC = j;
            }
        }
    }

    cout << "(" << maxR - mx + 1 << "," << maxC - mx + 1 << ") to (" << maxR << "," << maxC << ")" << endl;

    return mx * mx;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vi> mat(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maximalSquare(mat);

    return 0;
}
