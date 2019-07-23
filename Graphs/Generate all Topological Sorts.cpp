// https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/

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

void generateTopologicalSorts(vector<vi> &adj, vector<bool> &visited, vi &inDegree, vi &ans) {
    if (ans.size() == adj.size()) {
        for (int i : ans) cout << i << " ";
        cout << endl;
        return;
    }

    for (int u = 0; u < adj.size(); u++) {
        if (!visited[u] && inDegree[u] == 0) {
            for (int v : adj[u]) inDegree[v]--;
            ans.push_back(u);
            visited[u] = true;

            generateTopologicalSorts(adj, visited, inDegree, ans);

            // backtrack
            visited[u] = false;
            ans.pop_back();
            for (int v : adj[u]) inDegree[v]++;
        }
    }
}

int main() {
    int V, E, u, v;

    cin >> V >> E;
    vector<vi> adj(V);
    vi inDegree(V, 0);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<bool> visited(V, false);
    vi ans;
    generateTopologicalSorts(adj, visited, inDegree, ans);

    return 0;
}