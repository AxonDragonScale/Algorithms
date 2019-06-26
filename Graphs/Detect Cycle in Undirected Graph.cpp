// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

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

// This function is only for Undirected graphs
bool isCyclic(deque<int> *g, deque<bool> &visited, int cur, int parent) {
    visited[cur] = true;

    for (int i : g[cur]) {
        if (!visited[i]) {
            if (isCyclic(g, visited, i, cur)) {
                return true;
            }
            // if cycle is detected, we dont need to check more cycles, so return early
            // no return in other case, so dont do return isCyclic(...)
        } else {
            if (i != parent) {  // if already visited node is not its parent, then there is a cycle
                return true;    // (for directed graphs even if a visited node is not parent, it may not form a cycle)
            }
        }
    }

    return false;
}

int main() {
    int V, E, u, v;
    cin >> V >> E;

    deque<int> *g = new deque<int>[V];
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    deque<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclic(g, visited, i, -1)) {  // many components, check again for unvisited vertices
            cout << "Cycle Detected." << endl;
            return 0;
        }
    }

    cout << "No Cycle Detected." << endl;
    return 0;
}
