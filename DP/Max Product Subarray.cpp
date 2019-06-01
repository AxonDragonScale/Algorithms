// https://www.interviewbit.com/problems/max-product-subarray/

// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Return an integer corresponding to the maximum product possible.

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

int maxProductInSubarray(vector<int> &arr) {
    int n = arr.size();
    int ans = arr[0];

    int mx = ans, mn = ans;
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(mx, mn);
        }

        mx = max(arr[i], mx * arr[i]);
        mn = min(arr[i], mn * arr[i]);
        ans = max(ans, mx);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxProductInSubarray(arr) << endl;

    return 0;
}
