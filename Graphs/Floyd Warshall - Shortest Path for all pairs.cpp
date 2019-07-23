// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

// This gives the shortest path between all pairs of vertices

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
#define INF 1000000

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

void floydWarshall(vector<vi> &g) {
    int V = g.size();
    vector<vi> dist = g;

    for (int k = 0; k < V; k++) {          // intermediate
        for (int i = 0; i < V; i++) {      // source
            for (int j = 0; j < V; j++) {  // destination
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF  ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cin >> V;

    vector<vi> g(V, vi(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> g[i][j];
        }
    }

    floydWarshall(g);

    return 0;
}
