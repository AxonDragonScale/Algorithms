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

void DFSiterative(deque<int> *adj, deque<bool> &visited, int v) {
    deque<int> stack;

    stack.push_back(v);

    while (!stack.empty()) {
        v = stack.back();
        stack.pop_back();

        if (!visited[v]) {
            visited[v] = true;
            cout << v << " ";
        }

        for (auto it = adj[v].rbegin(); it != adj[v].rend(); it++) {
            int u = *it;
            if (!visited[u]) {
                stack.push_back(u);
            }
        }
    }
}

int main() {
    int e, n, u, v;
    cin >> n;

    deque<int> *adj = new deque<int>[n];
    deque<bool> visited(n, false);

    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSiterative(adj, visited, 0);
    cout << endl;

    return 0;
}
