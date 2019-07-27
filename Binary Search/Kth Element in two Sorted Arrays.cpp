// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

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

int kthElement(vi &arr1, vi &arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size();

    int l1 = 0, l2 = 0, r1 = n1 - 1, r2 = n2 - 1;
    while (l1 <= r1 && l2 <= r2) {
        int mid1 = l1 + (r1 - l1) / 2;
        int mid2 = l2 + (r2 - l2) / 2;

        if (l1 == r1) return arr2[k - l1];
        if (l2 == r2) return arr1[k - l2];

        if (mid1 + mid2 < k) {
            if (arr1[mid1] > arr2[mid2])
                l2 = mid2 + 1;
            else
                l1 = mid1 + 1;
        } else {
            if (arr1[mid1] > arr2[mid2])
                r1 = mid1;
            else
                r2 = mid2;
        }
    }
}

int main() {
    int n1, n2, k;
    cin >> n1 >> n2 >> k;

    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    cout << kthElement(arr1, arr2, k - 1);

    return 0;
}
