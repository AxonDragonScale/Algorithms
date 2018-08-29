/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* root;
 void util(TreeNode* A)
 {
    if(!A)
        return;
    if(!A->left&&!A->right)
    {
        root=A;
        return;
    }
    TreeNode* temp=A->right;
    if(A->left)
    {
        A->right=A->left;
        A->left=NULL;
        util(A->right);
        root->right=temp;
    }
    util(temp);
 }
 
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(!A)
        return A;
    util(A);
    return A;
}