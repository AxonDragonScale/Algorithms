// https://www.geeksforgeeks.org/bottom-view-binary-tree/

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
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

void bottomView(Node *root) {
    if (root == NULL) {
        return;
    }

    map<int, int> m;
    queue<pair<Node *, int> > q;
    q.push({root, 0});  // second is horizontal distance

    while (!q.empty()) {
        Node *cur = q.front().first;
        int d = q.front().second;
        q.pop();

        m[d] = cur->data;

        if (cur->left) q.push({cur->left, d - 1});
        if (cur->right) q.push({cur->right, d + 1});
    }

    for (pair<int, int> i : m) {
        cout << i.second << " ";
    }
    cout << endl;
}
