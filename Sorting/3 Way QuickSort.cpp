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

void partition(deque<int> &arr, int l, int r, int &i, int &j) {
    if (l + 1 >= r) {
        if (arr[l] > arr[r]) swap(arr[l], arr[r]);
        i = l;
        j = r;
        return;
    }

    int pivot = l + rand() % (r - l + 1);
    swap(arr[pivot], arr[r]);

    int mid = l;
    pivot = arr[r];
    while (mid <= r) {
        if (arr[mid] < pivot)
            swap(arr[l++], arr[mid++]);  // move to left and increment left
        else if (arr[mid] == pivot)
            mid++;
        else if (arr[mid] > pivot)
            swap(arr[mid], arr[r--]);  // dont increment mid since r needs to be processed
    }

    i = l - 1;
    j = mid;
}

void quickSort(deque<int> &arr, int l, int r) {
    if (l >= r) return;

    int i, j;
    partition(arr, l, r, i, j);

    quickSort(arr, l, i);
    quickSort(arr, j, r);
}

int main() {
    int n;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
