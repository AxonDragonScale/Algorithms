// Given n sorted points and k radars. Find the minimum range of the radars such that all points are covered

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

bool check(deque<int> &points, double radius, int k) {
    int req = 0;
    int cur = 0;

    while (cur < points.size()) {
        double centre = points[cur] + radius;

        cur++;
        while (cur < points.size() && abs(points[cur] - centre) < radius) {
            cur++;
        }

        req++;
    }

    return req <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    double lo = 0;
    double hi = 1 + (double)(points[n - 1] - points[0]) / (double)(2 * k);
    double epsilon = 1e-9;  // depends on precision you want, here we want 1e-6 of precision but use 1e-9 for buffer

    while (lo < hi - epsilon) {  // epsilon for floating point comparison, (lo will never be less than hi)
        double mid = (lo + hi) / 2;

        if (check(points, mid, k)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << lo << endl;

    return 0;
}
