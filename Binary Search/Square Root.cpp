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
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int l = 1, r = n, res;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (mid <= n / mid) {  // mid*mid <= n does not work?
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}
