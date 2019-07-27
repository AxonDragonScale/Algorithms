// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
// https://www.interviewbit.com/problems/longest-increasing-subsequence/

// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n-simple-implementation/

// Problems based on this approach -
// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// https://www.geeksforgeeks.org/print-maximum-length-chain-of-pairs/
// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
// https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/

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

int LIS(vector<int> &arr, int n) {
    vector<int> lis(n, 1);  // lis[i] holds length of LIS ending at i
    // LIS is atleast 1 for any sequence

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);  // if adding i after lis at j gives longer
            }
        }
    }

    int maxLen = 0;
    for (int i : lis) {
        maxLen = max(maxLen, i);
    }

    return maxLen;
}

// int LIS(vector<int> &arr, int n) {
//     vector<int> lis(n, 1);  // lis[i] holds length of LIS ending at i
//     lis[0] = 1;             // lis[0] is 1.    // not needed as lis for all i is atleast 1

//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
//                 lis[i] = lis[j] + 1;  // basically doing max(lis[i], lis[j] + 1)
//             }
//         }
//     }

//     int max = 0;
//     for (int i = 0; i < n; i++) {
//         if (max < lis[i]) max = lis[i];
//     }

//     return max;
// }

// nlogn
int LIS(vi &arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vi tail(n, 0);
    tail[0] = arr[0];
    int len = 1;  // next empty in tail

    for (int i = 1; i < n; i++) {
        if (tail[len - 1] < arr[i]) {
            tail[len++] = arr[i];
        } else {
            auto it = find(tail.begin(), tail.begin() + len, arr[i]);
            if (it != tail.begin() + len) continue;  // skip if already present

            it = upper_bound(arr.begin(), arr.begin() + len, arr[i]);
            *it = arr[i];
        }
    }

    // tail may not have LIS but len will be correct
    return len;
}

int main() {
    int t, n;
    cin >> t;

    vector<int> arr;

    while (t--) {
        cin >> n;

        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << LIS(arr, n) << endl;
    }

    return 0;
}