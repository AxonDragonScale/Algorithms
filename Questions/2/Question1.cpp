/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int util(TreeNode* A,int &max_ans)
 {
    if(!A)
        return 0;
    int left_sum=util(A->left,max_ans);
    int right_sum=util(A->right,max_ans);
    max_ans=max(max_ans,max(A->val+left_sum+right_sum,max(A->val+
    max(left_sum,right_sum),A->val)));
    return A->val+max(left_sum,right_sum);
 }
 
int Solution::maxPathSum(TreeNode* A) {
    if(!A)
        return 0;
    int max_ans=INT_MIN;
    util(A,max_ans);
    return max_ans;
}