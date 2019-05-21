// https://www.geeksforgeeks.org/check-given-graph-tree/

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

    // An 'Undirected' graph is a Tree if it doesnt have cycles and is fully connected
    deque<bool> visited(V, false);

    if (isCyclic(g, visited, 0, -1)) {
        cout << "Not a Tree" << endl;  //
    } else {
        for (bool i : visited) {
            if (i == false) {  // If a node has not been visited, graph is not fully connected
                cout << "Not a Tree" << endl;
                return 0;
            }
        }
        cout << "The graph is a Tree" << endl;
    }

    return 0;
}
