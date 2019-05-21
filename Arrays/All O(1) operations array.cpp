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

struct Array {
    vector<iPair> arr;
    iPair all;

    int time;

    Array(int n) {
        arr.resize(n);

        time = 0;
        all = {0, time++};
    }

    void set(int i, int val) { arr[i] = {val, time++}; }

    void setAll(int val) { all = {val, time++}; }

    int get(int i) {
        if (arr[i].ss > all.ss) {  // if arr has latest time stamp, use arr else use 'all'
            return arr[i].ff;
        } else {
            return all.ff;
        }
    }
};

int main() {
    Array arr(10);

    while (true) {
        int t, i, n;
        cin >> t;

        if (t == 0) {
            cin >> i;
            cout << arr.get(i) << endl;
        } else if (t == 1) {
            cin >> i >> n;
            arr.set(i, n);
        } else if (t == 2) {
            cin >> n;
            arr.setAll(n);
        } else {
            break;
        }
    }

    return 0;
}
