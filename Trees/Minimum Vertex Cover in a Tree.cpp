// A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph,
// either ‘u’ or ‘v’ is in vertex cover.

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
    int vc;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL), vc(-1) {}
};

int minVertexCover(Node *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 0;
    }

    if (root->vc != -1) {
        return root->vc;
    }

    // If root is included, it covers all children edges
    // children may or may not be included, so recurse for vertex covers of left and right subtrees
    int vcRootIncluded = 1 + minVertexCover(root->left) + minVertexCover(root->right);

    // If root is not included, the children must be included
    // grandchildren may or may not be included, so we recurse for them
    int vcRootNotIncluded = 0;
    if (root->left != NULL) {
        vcRootNotIncluded += 1 + minVertexCover(root->left->left) + minVertexCover(root->left->right);
    }
    if (root->right != NULL) {
        vcRootNotIncluded += 1 + minVertexCover(root->right->left) + minVertexCover(root->right->right);
    }

    root->vc = min(vcRootIncluded, vcRootNotIncluded);
    return root->vc;
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(8);
    root->left->left = new Node(8);
    root->left->right = new Node(8);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(8);
    root->right = new Node(8);
    root->right->right = new Node(8);

    cout << minVertexCover(root) << endl;

    return 0;
}
