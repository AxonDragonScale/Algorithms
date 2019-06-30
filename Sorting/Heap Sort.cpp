// https://www.geeksforgeeks.org/heap-sort/
// https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/tutorial/

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

// use stl
// void heapSort(vi &arr) {
//     make_heap(arr.begin(), arr.end());
//     sort_heap(arr.begin(), arr.end());
// }

// implementing yourself
void heapify(vi &arr, int root, int size) {
    int l = 2 * root + 1, r = 2 * root + 2;

    int largest = root;
    if (l < size && arr[l] > arr[largest]) largest = l;
    if (r < size && arr[r] > arr[largest]) largest = r;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, largest, size);
    }
}

void heapSort(vi &arr) {
    int n = arr.size();

    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
