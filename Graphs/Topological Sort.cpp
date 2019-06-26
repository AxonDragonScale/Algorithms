// https://www.geeksforgeeks.org/topological-sorting/
// For Directed Acyclic Graphs.
// If its cyclic, not possible. Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
// such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not
// possible if the graph is not a DAG.

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

void topologicalSort(int u, deque<int> *adj, deque<bool> &visited, deque<int> &s) {
    visited[u] = true;

    for (int i : adj[u]) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, s);
        }
    }

    s.push_back(u);
}

int main() {
    int n, e, u, v;

    cin >> n >> e;
    deque<int> *adj = new deque<int>[n];
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    deque<bool> visited(n, false);
    deque<int> s;  // stack

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, s);
        }
    }

    // print the result
    while (!s.empty()) {
        cout << s.back() << " ";
        s.pop_back();
    }
    cout << endl;

    return 0;
}
