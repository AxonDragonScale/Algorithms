// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

// Also see previous submission (your own not interviewbit) here ->
// https://www.interviewbit.com/problems/least-common-ancestor/

// Also do LCA using stored path

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
    if (root == NULL) {
        return NULL;
    } else if (root->data == a || root->data == b) {
        return root;
    }

    Node *leftLCA = LCA(root->left, a, b);
    Node *rightLCA = LCA(root->right, a, b);

    if (leftLCA && rightLCA) {
        return root;
    } else if (leftLCA == NULL) {
        return rightLCA;
    } else if (rightLCA == NULL) {
        return leftLCA;
    }
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

    cout << LCA(root, 11, 15)->data << endl;

    return 0;
}
