#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <queue>
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

// recursive insertBST
Node *insertBST(Node *root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (root->data > val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node *insertBSTIterative(Node *root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    Node *cur = root;
    while (true) {
        if (cur->data > val) {
            if (cur->left != NULL) {
                cur = cur->left;
            } else {
                cur->left = new Node(val);
                break;
            }
        } else {
            if (cur->right != NULL) {
                cur = cur->right;
            } else {
                cur->right = new Node(val);
                break;
            }
        }
    }

    return root;
}

int main() {
    Node *root = insertBSTIterative(NULL, 3);
    root = insertBSTIterative(root, 2);
    root = insertBSTIterative(root, 1);
    root = insertBSTIterative(root, 5);
    root = insertBSTIterative(root, 4);

    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->right->data << " ";
    cout << root->left->left->data << " ";
    cout << root->right->left->data << " ";

    return 0;
}