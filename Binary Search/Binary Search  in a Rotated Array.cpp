// https://www.interviewbit.com/problems/rotated-sorted-array-search/
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

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

// Better method
int method1(deque<int> &arr, int k) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == k) return mid;

        if (arr[l] <= arr[mid]) {               // Left part is sorted
            if (arr[l] <= k && k < arr[mid]) {  // if k lies in the left part
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {                                // Right part is sorted
            if (arr[mid] <= k && k < arr[r]) {  // if k lies in the right part
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    return -1;
}

// method2
int bSearch(deque<int> &arr, int k, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int findPivot(deque<int> &arr) {
    int n = arr.size();
    int l = 0, r = arr.size() - 1;

    if (arr[0] < arr[r]) return -1;  // Not rotated

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        } else if (arr[l] < arr[mid]) {  // left part is sorted, go right
            l = mid + 1;
        } else if (arr[mid] < arr[r]) {  // Right part is sorted, go left
            r = mid - 1;
        }
    }
}

int method2(deque<int> &arr, int k) {
    int n = arr.size();
    int l = 0, r = n - 1;

    int pivot = findPivot(arr);

    if (pivot == -1)
        return bSearch(arr, k, 0, n - 1);
    else if (arr[0] <= k)
        return bSearch(arr, k, 0, pivot - 1);
    else
        return bSearch(arr, k, pivot, n - 1);
}

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << method1(arr, k) << endl;

    return 0;
}
