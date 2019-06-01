// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

void util(TreeNode *root, int &k, int &ans) {  // basically do inorder
    if (root == NULL) return;

    util(root->left, k, ans);

    k--;
    if (k == 0) {
        ans = root->val;
        return;
    }

    util(root->right, k, ans);
}

int kthsmallest(TreeNode *root, int k) {
    int ans;
    util(root, k, ans);
    return ans;
}