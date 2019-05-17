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

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void topView(struct Node *root) {
    if (root == NULL) {
        return;
    }

    map<int, int> m;
    queue<pair<Node *, int> > q;
    q.push({root, 0});

    Node *cur;
    int d;
    while (!q.empty()) {
        cur = q.front().first;
        d = q.front().second;
        q.pop();

        if (m.find(d) == m.end()) {
            m[d] = cur->data;
        }

        if (cur->left != NULL) {
            q.push({cur->left, d - 1});
        }
        if (cur->right != NULL) {
            q.push({cur->right, d + 1});
        }
    }

    for (pair<int, int> i : m) {
        cout << i.second << " ";
    }
    cout << endl;
}
