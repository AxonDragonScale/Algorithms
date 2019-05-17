
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
// We can also do this by -
// save (level, node) pairs in the queue and keep a nextLevelToPrint
// when level == nextLevelToPrint (it will be at the first node of that level)
// and then increment nextLevelToPrint

// For RightView, we can save (level, node) pairs in a hashmap
// when we traverse a level, keep updating the map entry for that level
// In the end, all map entry will have the last node of their level

// do a BFS/level order and print first node of each level
void leftView(Node *root) {
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(NULL);
    q.push(root);

    Node *cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == NULL && !q.empty()) {
            cout << q.front()->data << " ";
            q.push(NULL);
            continue;
        }

        if (cur != NULL && cur->left != NULL) {
            q.push(cur->left);
        }
        if (cur != NULL && cur->right != NULL) {
            q.push(cur->right);
        }
    }
    cout << endl;
}

// can be done using DFS as well, like this
void leftViewUtil(Node *root, int h, int &minH) {
    if (root == NULL) {
        return;
    }

    if (h > minH) {  // we reached a new level
        minH = h;
        cout << root->data << " ";
    }

    leftViewUtil(root->left, h + 1, minH);
    leftViewUtil(root->right, h + 1, minH);
}

void leftView(Node *root) {
    int minH = -1;

    leftViewUtil(root, 0, minH);
    cout << endl;
}
