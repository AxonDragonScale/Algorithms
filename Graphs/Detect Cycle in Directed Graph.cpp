// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

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

bool isCyclicUtil(deque<int> *g, int cur, vector<bool> &visited, vector<bool> &onPath) {
    if (!visited[cur]) {
        visited[cur] = true;
        onPath[cur] = true;

        for (int i : g[cur]) {
            if (!visited[i] && isCyclicUtil(g, i, visited, onPath)) {
                return true;
            } else if (onPath[i]) {
                return true;
            }
        }

        onPath[cur] = false;
    }

    return false;
}

bool isCyclic(deque<int> *g, int V) {
    vector<bool> visited(V, false);
    vector<bool> onPath(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(g, i, visited, onPath)) {
            return true;
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
    }

    cout << isCyclic(g, V) << endl;

    return 0;
}
