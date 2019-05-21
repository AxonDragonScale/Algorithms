// Given a sorted array and a number k, check if there are 2 elements with sum k.

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

bool solveWithUnorderedSet(deque<int> &arr, int k) {
    unordered_set<int> arrSet;

    for (int i : arr) {
        if (arrSet.find(k - i) != arrSet.end()) {  // before inserting i, check if k-i is in set, if it is then true
            return true;
        }
        arrSet.insert(i);
    }

    return false;
}

bool solveWith2Pointers(deque<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = n - 1;  // your two pointers

    // if sum at i and j is > k, move j to left
    // if its < k, move i to right
    while (i < j) {
        if (arr[i] + arr[j] > k) {
            j--;
        } else if (arr[i] + arr[j] < k) {
            i++;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solveWith2Pointers(arr, k) << endl;

    return 0;
}