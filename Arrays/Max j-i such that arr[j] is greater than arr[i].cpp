// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

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

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi lMin(n), rMax(n);

    lMin[0] = arr[0];
    for (int i = 1; i < n; i++) lMin[i] = min(arr[i], lMin[i - 1]);
    // lMin[i] is the smallest element till i

    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) rMax[i] = max(arr[i], rMax[i - 1]);
    // rMax[i] is the largest element from i

    int i = 0, j = 0;
    int maxDiff = 0;
    while (i < n && j < n) {
        if (rMax[j] > lMin[i]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return 0;
}
