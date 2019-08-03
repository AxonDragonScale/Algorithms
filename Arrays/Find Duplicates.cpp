// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

// Given an array of n elements which contains elements from 1 to n, with any of these numbers appearing any number of
// times. Find these repeating numbers in O(n) and using only constant memory space.

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

vi getDuplicates(vi &arr) {
    int n = arr.size();

    vi duplicates;
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] >= 0)
            arr[abs(arr[i]) - 1] *= -1;
        else
            duplicates.push_back(arr[i]);
    }
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi ans = getDuplicates(arr);
    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}
