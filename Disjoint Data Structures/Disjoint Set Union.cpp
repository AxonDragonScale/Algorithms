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

struct DSU {
    deque<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {  // 1 based indexing, parent[0] is garbage value.
            parent[i] = i;
        }
    }

    // int root(int i) {  // returns root of i
    //     int temp = i;
    //     if (i != parent[i]) {
    //         i = parent[i];
    //     }

    //     parent[temp] = i;  // path compression -> Important  (save root so we dont have to do again next time)
    //     return i;
    // }

    int root(int i) {  // returns root of i
        if (i == parent[i]) {
            return i;
        }

        parent[i] = root(parent[i]);  // path compression (save root so we dont have to do again next time)
        // Using recursive version also saves root of intermediate elements as well, so better path compression
        return parent[i];
    }

    bool find(int a, int b) {  // checks if both a and b are in the same set
        return root(a) == root(b);
    }

    void connect(int a, int b) {  // usually called union (union is a keyword in c++)
        int aRoot = root(a);
        int bRoot = root(b);

        parent[bRoot] = aRoot;
    }
};

int main() {
    DSU dsu(5);
    dsu.connect(1, 2);
    dsu.connect(1, 4);
    cout << (dsu.root(2) == dsu.root(4)) << endl;

    return 0;
}