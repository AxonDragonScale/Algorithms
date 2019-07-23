// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
// https://ide.geeksforgeeks.org/Do157gzJig

// Djiskstra only works for positive weights

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

int main() {
    int E, V, u, v, w;
    cin >> V >> E;

    deque<iPair> *adj = new deque<iPair>[V];  // first is weight and second is vertex
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    deque<int> dist(V, INT_MAX);
    deque<bool> visited(V, false);
    priority_queue<iPair, deque<iPair>, greater<iPair> > minHeap;
    // stores dist from src and vertex

    minHeap.push(make_pair(0, 0));  // the second 0 is the src, from where we want to find the shortest path
    dist[0] = 0;                    // 0 is the src, and ofcourse dist of source is 0

    while (!minHeap.empty()) {
        int u = minHeap.top().ss;
        minHeap.pop();
        visited[u] = true;

        for (iPair i : adj[u]) {
            int w = i.ff;  // remember that first is weight not vertex
            int v = i.ss;

            if (!visited[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                minHeap.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Distances from vertex " << 0 << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " has distance " << dist[i] << endl;
    }

    return 0;
}
