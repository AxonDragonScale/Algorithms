// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
// (Notice that the list is preorder of tree)

TreeNode* flatten(TreeNode* root) {
    TreeNode *cur = root, *temp;

    while (cur) {
        if (cur->left) {
            temp = cur->left;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        } else {
            cur = cur->right;
        }
    }

    return root;
}