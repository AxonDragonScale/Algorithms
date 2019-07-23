// https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/

// Method -
// Do a DFS, if all vertices have not been visited in the DFS then its not connected and we return false.
// Reverse the graph. Do a DFS on reverse graph, if all vertices have been visited the its strongly connected.

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

void DFS(vector<vi> &adj, vector<bool> &visited, int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(adj, visited, v);
        }
    }
}

vector<vi> getTranspose(vector<vi> &adj) {
    int V = adj.size();
    vector<vi> tAdj(V);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            tAdj[v].push_back(u);
        }
    }

    return tAdj;
}

bool isStronglyConnected(vector<vi> &adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    DFS(adj, visited, 0);     // do dfs from 1st vertex
    for (bool i : visited) {  // if any vertex is not visited then graph is not connected
        if (!i) return false;
    }

    vector<vi> tAdj = getTranspose(adj);
    visited = vector<bool>(V, false);
    DFS(tAdj, visited, 0);    // do dfs of reverse graph
    for (bool i : visited) {  // if any vertex is not visited then not strongly connected
        if (!i) return false;
    }

    return true;
}

int main() {
    int E, V, u, v;
    cin >> V >> E;  // n is the number of vertices and E is edges

    vector<vi> adj(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isStronglyConnected(adj) << endl;

    return 0;
}