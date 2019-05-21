// Given a graph find if it is bipartite
// https://www.geeksforgeeks.org/bipartite-graph/

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

// Using BFS

bool checkBipartite(deque<int> *g, deque<int> &color, int V, int u) {
    deque<int> q;
    q.push_back(u);
    color[u] = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop_front();

        for (int i : g[u]) {
            if (color[i] == -1) {
                q.push_back(i);
                color[i] = 1 - color[u];
            } else if (color[i] == color[u]) {
                return false;
            }
        }
    }

    return true;
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

    deque<int> color(V, -1);  // -1 - not visited, 0 - red, 1 - blue
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {  // We have to run multiple times incase the graph is not strongly connected
            if (!checkBipartite(g, color, V, i)) {
                cout << "Not Bipartite" << endl;
                return 0;
            }
        }
    }

    cout << "Bipartite" << endl;
    return 0;
}

// DFS Method

// #include <algorithm>
// #include <climits>
// #include <cmath>
// #include <deque>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

// #define LN cout << __LINE__ << endl
// #define ff first
// #define ss second

// using namespace std;

// using iPair = pair<int, int>;
// using vi = vector<int>;
// using di = deque<int>;
// using lli = long long int;

// void checkBipartite(deque<int> *g, deque<int> &color, bool isBipartite, int cur, int curColor) {
//     if (color[cur] == 0) {
//         color[cur] = curColor;
//         for (auto i : g[cur]) {
//             if (curColor == 1) {
//                 checkBipartite(g, color, isBipartite, i, 2);
//             } else {
//                 checkBipartite(g, color, isBipartite, i, 1);
//             }
//         }
//     } else if (color[cur] != curColor) {
//         isBipartite = false;
//         return;
//     }
// }

// int main() {
//     int V, E, u, v;
//     cin >> V >> E;

//     deque<int> g[V];
//     for (int i = 0; i < E; i++) {
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     deque<int> color(V, 0);  // 0 - not visited, 1 - red, 2 - blue
//     bool isBipartite = true;

//     checkBipartite(g, color, isBipartite, 0, 1);

//     return 0;
// }