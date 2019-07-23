// https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

// https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
// https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
// method 1
void inOrder(Node *root, Node *&prev) {
    if (root) {
        inOrder(root->left, prev);

        root->left = prev;
        if (prev) prev->right = root;
        prev = root;

        inOrder(root->right, prev);
    }
}

void bToDLL(Node *root, Node **head_ref) {
    Node *prev = NULL;
    inOrder(root, prev);

    while (root->left) root = root->left;
    *head_ref = root;
}

// or method 2
void inOrder(Node *root, Node **head_ref) {
    if (root) {
        static Node *prev = NULL;

        inOrder(root->left, prev);

        if (*head_ref == NULL) {
            prev = NULL;  // ust for multiple test cases
            *head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        inOrder(root->right, prev);
    }
}

// We can also just do an inorder traversal and save all nodes in a vector and just connect them later