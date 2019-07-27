// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

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

struct Edge {
    int u;
    int v;
    int w;
};

bool comp(const Edge &a, const Edge &b) { return a.w < b.w; }

int root(deque<int> &components, int i) {
    while (i != components[i]) {
        i = components[i];
    }

    return i;
}

// union
void connect(deque<int> &components, int a, int b) {
    int aRoot = root(components, a);
    int bRoot = root(components, b);

    components[bRoot] = aRoot;
}

bool isConnected(deque<int> &components, int a, int b) { return root(components, a) == root(components, b); }

int main() {
    int e, n, u, v, w;
    cin >> n >> e;

    deque<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    // sort all edges according to their weights
    sort(edges.begin(), edges.end(), comp);

    // component array for union find, initially each element is its own parent/root
    deque<int> components(n);
    for (int i = 0; i < n; i++) {
        components[i] = i;
    }

    int mst = 0;
    deque<Edge> mstEdges;
    // Add edges into the MST from lowest weight to highest weight.
    // Don't add edge if it makes a loop (isConnected)
    for (int i = 0; i < e; i++) {
        if (!isConnected(components, edges[i].u, edges[i].v)) {
            connect(components, edges[i].u, edges[i].v);
            mst += edges[i].w;
            mstEdges.push_back(edges[i]);
        }
    }

    cout << "Weight of MST :" << mst << endl;
    cout << "Edges :" << endl;
    for (Edge edge : mstEdges) {
        cout << edge.u << "-->" << edge.v << " with weight " << edge.w << endl;
    }

    return 0;
}
