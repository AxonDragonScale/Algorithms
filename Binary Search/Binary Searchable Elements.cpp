// Given an unsorted array, print whether each element is binary searchable or not

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

void isSearchable(deque<int> &arr, deque<bool> &ans, int l, int r, int min, int max) {
    if (l > r) {
        return;
    }

    int curIndex = (l + r) / 2;
    if (min <= arr[curIndex] && arr[curIndex] <= max) {
        ans[curIndex] = true;
    }

    isSearchable(arr, ans, l, curIndex - 1, min, arr[curIndex] - 1);
    isSearchable(arr, ans, curIndex + 1, r, arr[curIndex] + 1, max);
}

int main() {
    int n;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    deque<bool> ans(n, false);
    isSearchable(arr, ans, 0, n - 1, INT_MIN, INT_MAX);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " - " << ans[i] << endl;
    }

    return 0;
}
