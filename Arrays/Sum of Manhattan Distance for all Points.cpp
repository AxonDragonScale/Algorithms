// https://www.geeksforgeeks.org/sum-manhattan-distances-pairs-points/

// Given n points. The task is to find sum of manhattan distance between all pairs of coordinates.
// Manhattan Distance between two points (x1, y1) and (x2, y2) is |x1 – x2| + |y1 – y2|

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

int distanceSum(vi &arr) {
    sort(arr.begin(), arr.end());

    int ans = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans += arr[i] * i - sum;
        sum += arr[i];
    }

    return ans;
}

int manhattanDistanceSum(vi &x, vi &y) { return distanceSum(x) + distanceSum(y); }

int main() {
    int n;
    cin >> n;

    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout

        return 0;
}
