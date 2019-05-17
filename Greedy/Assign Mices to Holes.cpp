// https://www.geeksforgeeks.org/assign-mice-holes/

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

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<int> mice(n);
        for (int i = 0; i < n; i++) {
            cin >> mice[i];
        }

        deque<int> holes(n);
        for (int i = 0; i < n; i++) {
            cin >> holes[i];
        }

        // if we sort mice and holes and assign the ith mice to the ith hole, each mice is assigned to closest hole
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());

        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            maxTime = max(maxTime, abs(mice[i] - holes[i]));
        }

        cout << maxTime << endl;
    }

    return 0;
}
