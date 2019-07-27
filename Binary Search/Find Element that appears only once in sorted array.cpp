// https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/

// Given a sorted array in which all elements appear twice (one after one) and one element appears only once. Find that
// element in O(log n) complexity.

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

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1])
                l = mid + 2;
            else
                r = mid;
        } else {
            if (arr[mid - 1] == arr[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    cout << arr[l] << endl;

    return 0;
}
