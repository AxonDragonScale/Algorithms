// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
// (Notice that the list is preorder of tree)

TreeNode* flatten(TreeNode* root) {
    TreeNode *cur = root, *temp;

    while (cur) {
        if (cur->left) {
            temp = cur->left;
            while (temp->right) {  // go to rightmost child in left subtree
                temp = temp->right;
            }
            temp->right = cur->right;  // attach cur's right subtree to its right
            cur->right = cur->left;
            cur->left = NULL;
        } else {
            cur = cur->right;
        }
    }

    return root;
}