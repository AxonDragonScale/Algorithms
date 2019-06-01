#include <algorithm>
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

// first mulitply all then divide to avoid decimal errors
lli binomialCoeff(int n, int k) {
    lli res = 1;
    k = min(k, n - k);

    for (int i = 0; i < k; i++) {
        res *= (n - i);
    }

    for (int i = 1; i <= k; i++) {
        res /= i;
    }

    return res;
}

// DP method (if you are going to frequently do this)

// int getnCk(deque<di> &nCk, int n, int k) {
//     if (k > n) return 0;
//     if (n <= 1 || k == 0) return 1;

//     if(nCk[n][k] != -1) return nCk[n][k];
//     nCk[n][k] = getnCk(nCk, n-1, k-1) + getnCk(nCk, n-1, k);
//     return nCk[n][k];
// }

int main() {
    int n, k;
    cin >> n >> k;

    cout << binomialCoeff(n, k) << endl;

    // deque<di> nCk(n, di(n, -1));
    // cout<<getnCk(nCk, n, k);

    return 0;
}
