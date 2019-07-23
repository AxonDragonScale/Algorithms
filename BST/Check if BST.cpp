// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// https://practice.geeksforgeeks.org/problems/check-for-bst/1

// method 1
bool isBSTUtil(Node *root, int min, int max) {
    if (root == NULL) return true;

    if (min <= root->data && root->data <= max) {
        return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
    } else {
        return false;
    }
}

bool isBST(Node *root) { return isBSTUtil(root, INT_MIN, INT_MAX); }

// method 2
bool isBST(Node *root, Node *l = NULL, Node *r = NULL) {
    if (root == NULL) return true;

    if (l != NULL && l->data > root->data) return false;
    if (r != NULL && r->data < root->data) return false;

    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

// method 3
bool isBST(Node *root) {
    static Node *prev = NULL;
    if (!root) return true;

    if (!isBST(root->left)) return false;

    if (prev != NULL && prev->data > root->data) return false;
    prev = root;

    if (!isBST(root->right)) return false;

    return true;
}