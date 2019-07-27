// https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/

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

int main() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n == 1) return 0;

    sort(arr.begin(), arr.end());
    int ans = arr[n - 1] - arr[0];
    int l = arr[0] + k;
    int r = arr[n - 1] - k;
    if (l < r) swap(l, r);

    for (int i = 1; i < n - 1; i++) {
        int sub = arr[i] - k;
        int add = arr[i] + k;

        if (sub >= l && add <= r) continue;

        if (r - sub <= add - l)
            l = sub;
        else
            r = add;
    }

    cout << min(ans, r - l);

    return 0;
}
