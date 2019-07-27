// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

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

int longestCommonSubstr(string &a, string &b) {
    int aSize = a.size(), bSize = b.size();

    vector<vi> lcs(aSize + 1, vi(bSize));
    // lcs[i][j] is the longest common suffix (not substr) in a[0..i-1] and b[0..j-1]

    int ans = 0;
    for (int i = 0; i <= aSize; i++) {
        for (int j = 0; j <= bSize; j++) {
            if (i == 0 && j == 0) {
                lcs[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                ans = max(ans, lcs[i][j]);
            } else {
                lcs[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << longestCommonSubstr(a, b) << endl;

    return 0;
}
