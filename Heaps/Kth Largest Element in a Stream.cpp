// given a stream (size n is too big to save in array), find the kth largest element

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
    int n, k, temp;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        minHeap.push(temp);
    }

    for (int i = k; i < n; i++) {
        cin >> temp;

        if (minHeap.top() < temp) {
            minHeap.pop();
            minHeap.push(temp);
        }
    }

    cout << minHeap.top() << endl;

    return 0;
}
