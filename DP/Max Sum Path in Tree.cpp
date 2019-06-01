// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
// Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

// Best Solution
int util(TreeNode *root, int &ans) {
    if (root == NULL) return 0;

    int lSum = max(0, util(root->left, ans));
    int rSum = max(0, util(root->right, ans));
    // If the left and right sums are -ve, max sum path could just end at here
    ans = max(ans, lSum + rSum + root->val);

    return max(lSum, rSum) + root->val;
}

int Solution::maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    util(root, ans);
    return ans;
}

// My Method
int util(TreeNode *root, unordered_map<TreeNode *, int> &dp) {
    if (root == NULL) return 0;

    if (dp.find(root) != dp.end()) return dp[root];

    int lSum = util(root->left, dp);
    int rSum = util(root->right, dp);

    return dp[root] = max(lSum, rSum) + root->val;
}

int Solution::maxPathSum(TreeNode *root) {
    unordered_map<TreeNode *, int> dp;
    dp[NULL] = 0;
    util(root, dp);

    int ans = INT_MIN, temp;
    for (pair<TreeNode *, int> p : dp) {
        if (p.first == NULL) continue;
        temp = p.first->val + max(0, dp[p.first->left]) + max(0, dp[p.first->right]);
        ans = max(temp, ans);
    }

    return ans;
}