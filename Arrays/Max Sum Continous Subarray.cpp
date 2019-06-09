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

int maxSumSubArray(const deque<int> &arr) {
    int max = INT_MIN;
    int curMax = 0;

    for (int i = 0; i < arr.size(); i++) {
        curMax += arr[i];
        max = std::max(max, curMax);
        if (curMax < 0) {
            curMax = 0;
        }
    }

    return max;
}

int main() {
    int n;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSumSubArray(arr);

    return 0;
}
