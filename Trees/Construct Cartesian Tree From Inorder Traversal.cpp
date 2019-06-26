// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

// Given an inorder traversal of a cartesian tree, construct the tree.
// Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree.

TreeNode *util(vector<int> &arr, int l, int r) {
    if (l > r) return NULL;

    int maxIdx = l;
    for (int i = l; i <= r; i++) {
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }

    TreeNode *root = new TreeNode(arr[maxIdx]);
    root->left = util(arr, l, maxIdx - 1);
    root->right = util(arr, maxIdx + 1, r);

    return root;
}

TreeNode *Solution::buildTree(vector<int> &arr) { return util(arr, 0, arr.size() - 1); }