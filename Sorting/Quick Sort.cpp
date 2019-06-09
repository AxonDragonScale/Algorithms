// https://www.interviewbit.com/tutorial/quicksort-algorithm/
// https://www.geeksforgeeks.org/quick-sort/ -> VERY GOOD (extras)

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

int partition(deque<int> &arr, int l, int r) {
    int pivot = l + rand() % (r - l + 1);
    swap(arr[pivot], arr[r]);  // move pivot to last element

    int i = l;
    pivot = l;  // arr[pivot] will always have element thats >= than pivot (or is unprocessed)
    while (i < r) {
        if (arr[i] < arr[r]) {
            swap(arr[i], arr[pivot]);
            pivot++;
        }
        i++;
    }

    swap(arr[pivot], arr[r]);
    return pivot;
}

void quickSort(deque<int> &arr, int l, int r) {
    if (l < r) {
        int pivot = partition(arr, l, r);

        quickSort(arr, l, pivot);
        quickSort(arr, pivot + 1, r);
    }
}

void quickSortIterative(deque<int> &arr) {
    int l = 0, r = arr.size() - 1;
    stack<iPair> s;
    s.push({l, r});

    while (!s.empty()) {
        iPair p = s.top();
        s.pop();

        l = p.ff;
        r = p.ss;
        if (l >= r) continue;

        int pivot = partition(arr, l, r);
        s.push({l, pivot});
        s.push({pivot + 1, r});
    }
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
