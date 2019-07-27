// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/      --> Good
// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

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
    int e, n, u, v, w;
    cin >> n >> e;

    deque<iPair> *adj = new deque<iPair>[n];
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    deque<bool> mstSet(n, false);
    deque<int> parent(n, -1);
    deque<int> cost(n, INT_MAX);

    priority_queue<iPair, deque<iPair>, greater<iPair> > minHeap;  // {weight, node}
    int mst = 0;

    int src = 0;
    cost[src] = 0;
    minHeap.push({cost[src], src});

    while (!minHeap.empty()) {
        int u = minHeap.top().ss;
        int wu = minHeap.top().ff;
        minHeap.pop();

        if (!mstSet[u]) {
            mstSet[u] = true;
            mst += wu;

            for (iPair i : adj[u]) {
                int v = i.ff;
                int wv = i.ss;
                if (!mstSet[v] && cost[v] > wv) {
                    // cost[v] > wv is just for optimization, cost array is not needed at all.
                    parent[v] = u;
                    cost[v] = wv;
                    minHeap.push({wv, v});
                }
            }
        }
    }

    cout << "MST = " << mst << endl;
    for (int i = 0; i < n; i++) {
        cout << parent[i] << "-->" << i << endl;
    }

    return 0;
}
