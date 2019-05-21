// You are given n interval in the range [1, m]
// for every integer, count how many intervals does it lie in.

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

struct Interval {
    int start;
    int end;
};

int main() {
    int n, m;
    cin >> n >> m;

    deque<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    deque<int> arr(m + 1, 0);
    for (Interval interval : intervals) {  // dont need to save the interval, we can do this while taking input
        arr[interval.start] += 1;          // mark the start
        arr[interval.end] -= 1;            // mark the end
    }

    // In arr, every time we see a +1, the elements from there are included in one more interval
    // so we have to add to them
    // every time we see a -1, interval ended

    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += arr[i];  //
        cout << i << "  is in " << sum << " intervals" << endl;
    }

    return 0;
}
