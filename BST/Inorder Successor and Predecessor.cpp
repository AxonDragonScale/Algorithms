// https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/

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
    Node *left;
    Node *right;
};

Node *successor(Node *root, int k) {
    Node *succ = NULL;

    while (root != NULL) {
        if (root->data == k) {
            if (root->right != NULL) {
                Node *temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                succ = temp;
            }

            return succ;
        } else if (root->data > k) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return NULL;
}

Node *predecessor(Node *root, int k) {
    Node *pred = NULL;

    while (root != NULL) {
        if (root->data == k) {
            if (root->left != NULL) {
                Node *temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                pred = temp;
            }

            return pred;
        } else if (root->data < k) {
            pred = root;
            root = root->right;
        } else {
            root = root->right;
        }
    }

    return NULL;
}

// We can get both in same function as well -> use pointers as reference
void getSuccPred(Node *root, int k, Node *&succ, Node *&pred) {
    succ = NULL;
    pred = NULL;

    while (root != NULL) {
        if (root->data == k) {
            if (root->right != NULL) {
                Node *temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                succ = temp;
            }

            if (root->left != NULL) {
                Node *temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                pred = temp;
            }

            return;
        } else if (root->data > k) {
            succ = root;
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
}

int main() {
    // the code

    return 0;
}
