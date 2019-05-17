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

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *LCA(Node *root, int a, int b) {
    Node *cur = root;

    while (true) {
        if (cur->data > a && cur->data > b) {
            cur = cur->left;
        } else if (cur->data < a && cur->data < b) {
            cur = cur->right;
        } else {
            break;
        }
    }

    return cur;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->left->left = new Node(11);
    root->right->right = new Node(15);

    cout << LCA(root, 5, 15)->data << endl;

    return 0;
}
