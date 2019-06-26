// https://www.interviewbit.com/problems/recover-binary-search-tree/
// TODO -> Look at interviewbit's solutions

void inOrder(vector<int> &ans, TreeNode *root, int &prev, bool &done) {
    if (!root) return;

    inOrder(ans, root->left, prev, done);

    if (root->val < prev && !done) {
        done = true;
        ans.push_back(prev);
        return;
    } else {
        prev = root->val;
    }

    inOrder(ans, root->right, prev, done);
}

void revInOrder(vector<int> &ans, TreeNode *root, int &prev, bool &done) {
    if (!root) return;

    revInOrder(ans, root->right, prev, done);

    if (root->val > prev && !done) {
        done = true;
        ans.push_back(prev);
        return;
    } else {
        prev = root->val;
    }

    revInOrder(ans, root->left, prev, done);
}

vector<int> Solution::recoverTree(TreeNode *root) {
    vector<int> ans;
    int temp1 = INT_MAX, temp2 = INT_MIN;
    bool done1 = false, done2 = false;
    revInOrder(ans, root, temp1, done1);
    inOrder(ans, root, temp2, done2);

    return ans;
}