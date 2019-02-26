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

void DFS(deque<int> *adj, deque<bool> &visited, int v) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(adj, visited, u);
        }
    }
}

int main() {
    int e, n, u, v;
    cin >> n;  // n is the number of vertices

    // deque<iPair> *adj for weighted graphs
    deque<int> *adj = new deque<int>[n];
    deque<bool> visited(n, false);

    cin >> e;  // e is the number of edges
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove for directed graphs
    }

    DFS(adj, visited, 0);  // here 0 is the node where DFS starts
    cout << endl;

    return 0;
}