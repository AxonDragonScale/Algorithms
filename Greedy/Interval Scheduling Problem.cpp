
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

#include <algorithm>
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

struct interval {
    lli i;  // index
    lli s;
    lli f;
};

bool comparator(const interval a, const interval b) { return a.f < b.f; }

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        deque<interval> meetings(n);
        for (int i = 0; i < n; i++) {
            cin >> meetings[i].s;
            meetings[i].i = i + 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> meetings[i].f;
        }

        sort(meetings.begin(), meetings.end(), comparator);

        lli minTime = -1;
        for (int i = 0; i < n; i++) {
            if (meetings[i].s > minTime) {
                cout << meetings[i].i << " ";
                minTime = meetings[i].f;
            }
        }
        cout << endl;
    }

    return 0;
}