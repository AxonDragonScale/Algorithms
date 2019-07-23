// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
// Same as djikstra but also works for negative weights. And its O(VE) while djikstra is O(VlogV)

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

struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    int V, E, u, v, w, src;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    cin >> src;

    deque<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // There cant be a shortest path if graph has a negative weight cycle.
    for (Edge e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.v] > dist[e.u] + e.w) {
            cout << "Graph has negative weight cycle." << endl;
        }
    }

    for (int d : dist) cout << d << " ";
    cout << endl;

    return 0;
}