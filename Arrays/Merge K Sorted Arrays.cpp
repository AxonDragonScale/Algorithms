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

struct Node {
    int data;
    int indexOfArray;
    int indexInArray;
};

struct Comp {
    bool operator()(const Node &a, const Node &b) { return a.data > b.data; }
};

int main() {
    int k;
    cin >> k;

    vector<vector<int>> arrays(k);
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        arrays[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> arrays[i][j];
        }
    }

    priority_queue<Node, vector<Node>, Comp> minHeap;
    for (int i = 0; i < k; i++) minHeap.push({arrays[i][0], i, 0});

    vector<int> ans;
    while (!minHeap.empty()) {
        Node cur = minHeap.top();
        minHeap.pop();

        ans.push_back(cur.data);
        if (cur.indexInArray + 1 < arrays[cur.indexOfArray].size())
            minHeap.push({arrays[cur.indexOfArray][cur.indexInArray + 1], cur.indexOfArray, cur.indexInArray + 1});
    }

    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}