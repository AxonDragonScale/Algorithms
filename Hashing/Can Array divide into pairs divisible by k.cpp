// https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/

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

bool canDivide(vi &arr, int k) {
    int n = arr.size();
    if (n % 2 != 0) return false;

    map<int, int> freq;
    for (int i : arr) freq[arr[i] % k]++;

    for (int i : arr) {
        int rem = arr[i] % k;

        if (2 * rem == k || rem == 0) {  // if rem is k/2 or 0, then elements that give rem should occur even times
            if (freq[rem] % 2 != 0) return false;
        } else if (freq[rem] != freq[k - rem]) {  // rem and k-rem should occur even times
            return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;
    cout << canDivide(arr, k) << endl;

    return 0;
}
