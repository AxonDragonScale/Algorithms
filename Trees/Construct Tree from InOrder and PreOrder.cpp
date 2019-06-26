// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

TreeNode *util(vector<int> &preOrder, vector<int> &inOrder, unordered_map<int, int> &inOrderIndex, int inL, int inR,
               int &pIdx) {
    if (inL > inR) return NULL;

    TreeNode *root = new TreeNode(preOrder[pIdx]);
    int inIdx = inOrderIndex[preOrder[pIdx]];
    pIdx++;

    root->left = util(preOrder, inOrder, inOrderIndex, inL, inIdx - 1, pIdx);
    root->right = util(preOrder, inOrder, inOrderIndex, inIdx + 1, inR, pIdx);
    return root;
}

TreeNode *Solution::buildTree(vector<int> &preOrder, vector<int> &inOrder) {
    unordered_map<int, int> inOrderIndex;  // its given that elements are distinct
    for (int i = 0; i < inOrder.size(); i++) {
        inOrderIndex[inOrder[i]] = i;
    }

    int pIdx = 0;
    return util(preOrder, inOrder, inOrderIndex, 0, inOrder.size() - 1, pIdx);
}