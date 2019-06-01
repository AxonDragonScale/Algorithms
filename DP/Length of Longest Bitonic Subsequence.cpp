// https://www.interviewbit.com/problems/length-of-longest-subsequence/
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/  -> O(n^2)
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-onlogn/   -> TODO - its O(nlogn)

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

// Longest bitonic subsequence: lis ending at i + lds starting at i
int lbs(const vector<int> &arr) {
    int n = arr.size();

    vector<int> lis(n, 1);  // lis[i] is length of LIS ending at i
    vector<int> lds(n, 1);  // lds[i] is length of LDS starting at i
    // LIS - Longest Increasing Subsequence , LDS - Longest Decreasing Subsequence
    // LIS and LDS for any i are atleast 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {  // i > j
            if (arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {  // i < j
            if (arr[i] > arr[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, lis[i] + lds[i] - 1);  // ith element is included twice
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << lbs(arr) << endl;

    return 0;
}
