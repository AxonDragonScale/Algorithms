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

// better
int findPivot(deque<int> &arr) {
    int n = arr.size();
    int l = 0, r = n - 1;

    if (arr[0] < arr[r]) return 0;  // Not rotated

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1]) {
            return mid;
        } else if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        } else if (arr[l] < arr[mid]) {  // left part is sorted, go right
            l = mid + 1;
        } else if (arr[mid] < arr[r]) {  // Right part is sorted, go left
            r = mid - 1;
        }
    }
}

void findMin(di &arr) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (arr[mid] > arr[r])  // then lowest/pivot is in (mid, r]
            l = mid + 1;
        else  // lowest/pivot is in [l, mid]
            r = mid;
    }

    if (l == r) {
        cout << "Min element is " << arr[l] << " at index " << l << endl;
    }
}

int main() {
    int n;
    cin >> n;

    di arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findPivot(arr) << endl;  // index of pivot
    findMin(arr);

    return 0;
}