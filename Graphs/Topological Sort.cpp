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

// Push the vertex in the stack only after all the adjacent vertices have already been pushed.
// So, this is just dfs but we push to stack at the end of the function
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
    int V, E, u, v;

    cin >> V >> E;
    deque<int> *adj = new deque<int>[V];
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    deque<bool> visited(V, false);
    deque<int> s;  // stack

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, s);
        }
    }

    // print the stack
    while (!s.empty()) {
        cout << s.back() << " ";
        s.pop_back();
    }
    cout << endl;

    return 0;
}

// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

int main() {
    int V, E, u, v;

    cin >> V >> E;
    deque<int> *adj = new deque<int>[V];
    deque<int> inDegree(V, 0);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    deque<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q.push_back(i);
    }

    deque<int> ans;
    while (!q.empty()) {
        u = q.front();
        q.pop_front();

        ans.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push_back(v);
        }
    }

    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}