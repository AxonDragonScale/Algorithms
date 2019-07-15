// https://www.geeksforgeeks.org/counting-inversions/

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

int mergeAndCountInv(vi &arr, vi &temp, int l, int mid, int r) {
    int i = l, j = mid + 1;
    int k = l;
    int invCount = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int sortAndCountInv(vi &arr, vi &temp, int l, int r) {
    if (l >= r) return 0;

    int mid = l + (r - l) / 2;
    int invCount = sortAndCountInv(arr, temp, l, mid);
    invCount += sortAndCountInv(arr, temp, mid + 1, r);
    invCount += mergeAndCountInv(arr, temp, l, mid, r);

    return invCount;
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi temp(n);
    cout << sortAndCountInv(arr, temp, 0, n - 1) << endl;
    for (int i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
