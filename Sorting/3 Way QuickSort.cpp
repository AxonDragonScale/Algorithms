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

int partition(deque<int> &arr, int l, int r) {}

void quickSort(deque<int> &arr, int l, int r) {}

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
