#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
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

// Find the size of the tree
int size(Node *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + size(root->left) + size(root->right);
}

// Find the height of the tree
int height(Node *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

// Find the depth of the node which had key
int depth(Node *root, int key) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == key) {
        return 0;
    }

    int dLeft = depth(root->left, key);
    int dRight = depth(root->right, key);

    if (dLeft != -1) return 1 + dLeft;
    if (dRight != -1) return 1 + dRight;
    return -1;
}

// minDepth - The path has to end on a leaf node
int minDepth(Node *root) {
    if (root == NULL) return 100000000;         // not INT_MAX as adding to it will give overflow
    if (!root->left && !root->right) return 1;  // leaf

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Find the number of leaf nodes in the tree
int noOfLeafNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
    }
}

// Check if two trees are identical
bool isIdentical(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) {
        return false;
    } else if (root1->data == root2->data) {
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    } else {
        return false;
    }
}

// Check if 2 trees are mirrors of each other
bool isMirror(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) {
        return false;
    } else if (root1->data == root2->data) {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
}

// Check if a tree is Symmetric (is its own Mirror)
// https://www.interviewbit.com/problems/symmetric-binary-tree/
// Basically, check if left and right subtrees are mirrors of each other
bool isSymmetricHelper(Node *root1, Node *root2) {
    if (!root1 || !root2) {
        if (root1 || root2)
            return false;
        else
            return true;
    }

    if (root1->data == root2->data) {
        return isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left);
    } else {
        return false;
    }
}

bool isSymmetric(Node *root) {
    if (root == NULL) {
        return true;
    }

    return isSymmetricHelper(root->left, root->right);
}

// https://www.interviewbit.com/problems/invert-the-binary-tree/
Node *invertTree(Node *root) {
    if (root == NULL) return NULL;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Check if the tree is balanced
bool isBalanced(Node *root) {
    if (root == NULL) {
        return true;
    }

    int hLeft = height(root->left);
    int hRight = height(root->right);

    return abs(hLeft - hRight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

// Efficient Version of isBalanced
// Returns height if subtree is balanced, -1 otherwise
int isBalancedUtil(Node *root) {
    if (root == NULL) return 0;

    int lHeight = isBalancedUtil(root->left);
    int rHeight = isBalancedUtil(root->right);

    if (lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
        return -1;
    else
        return 1 + max(lHeight, rHeight);
}

bool isBalanced(Node *root) {
    if (isBalancedUtil(root) == -1)
        return false;
    else
        return true;
}

// diameter is number of nodes in the longest path between any 2 leaf nodes in the tree
int diameter(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int hLeft = height(root->left);
    int hRight = height(root->right);

    return max(1 + hLeft + hRight, max(diameter(root->left), diameter(root->right)));
}

// A complete tree has all levels full except the last.
bool isCompleteUtil(Node *root, int idx, int &numNodes) {
    if (root == NULL) return true;
    if (idx >= numNodes) return false;

    return isCompleteUtil(root, 2 * idx + 1, numNodes) && isCompleteUtil(root, 2 * idx + 2, numNodes);
}

int countNodes(Node *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node *root) {
    int idx = 0;
    int numNodes = countNodes(root);
    return isCompleteUtil(root, idx, numNodes);
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
}