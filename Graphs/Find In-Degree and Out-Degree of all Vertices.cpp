#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

void findInAndOutDegrees(deque<deque<int>> &g) {
    int V = g.size();

    vector<int> inDegree(V, 0);
    vector<int> outDegree(V, 0);

    for (int i = 0; i < V; i++) {
        outDegree[i] = g[i].size();

        for (int u : g[i]) {
            inDegree[u]++;
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " had InDegree " << inDegree[i] << " and OutDegree " << outDegree[i] << endl;
    }
}

int main() {
    int V, E, u, v;
    cin >> V >> E;

    deque<deque<int>> g(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }

    findInAndOutDegrees(g);

    return 0;
}
