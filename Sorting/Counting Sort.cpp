// https://www.geeksforgeeks.org/counting-sort/
// https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/

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

// Not a Comparison based sort.
// In Counting sort, the frequencies of distinct elements of the array to be sorted is counted and stored in an
// auxiliary array, by mapping its value as an index of the auxiliary array.
// This should be used when all elements are in [0..10^6]. Gives performance benefits if elements are duplicated a lot.
// If all elements are in a range [m..n] then use unordered_map to store count. (n-m should be small enough store that
// many elements)
// This is O(n + mx)
void countingSort(vi &arr) {
    int n = arr.size();
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> count(mx + 1, 0);
    for (int i : arr) count[i]++;

    int i = 0;
    for (int j = 0; j <= mx; j++) {
        while (count[j]--) {
            arr[i++] = j;
        }
    }
}

// stable
void countingSort(vi &arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int n = arr.size(), range = max - min + 1;

    vector<int> count(range, 0), output(n);

    for (int i : arr) count[i - min]++;
    for (int i = 1; i < n; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
