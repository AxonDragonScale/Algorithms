// https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// https://www.geeksforgeeks.org/insertion-sort/

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

// Insertion sort is based on the idea that one element from the input elements is consumed in each iteration to find
// its correct position i.e, the position to which it belongs in a sorted array.
// It can be useful when input array is almost sorted, only few elements are misplaced in complete big array.
void insertionSort(vi &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int cur = arr[i];

        while (j >= 0 && arr[j] > cur) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = cur;
    }
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
