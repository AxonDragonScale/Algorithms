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

void BFS(deque<int> *adj, deque<bool> &visited, int v) {
    deque<int> queue;

    visited[v] = true;
    queue.push_back(v);

    while (!queue.empty()) {
        v = queue.front();
        queue.pop_front();

        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                queue.push_back(u);
            }
        }
    }
}

int main() {
    int e, n, u, v;
    cin >> n;

    // deque<iPair> *adj for weighted graphs
    deque<int> *adj = new deque<int>[n];
    deque<bool> visited(n, false);

    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove for directed graph
    }

    BFS(adj, visited, 0);  // here 0 is the node where BFS starts
    cout << endl;

    return 0;
}
