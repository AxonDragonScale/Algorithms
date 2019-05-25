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

int main() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == k) {
            cout << mid << endl;
            return 0;
        } else if (arr[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << -1 << endl;

    return 0;
}