// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

// Also see interviewbit solution, same concept but different implentation

// last of postOrder is root of current subtree, pIdx is last. pIdx-1 may be root of its left or right subtree
// first it would be right subtree if not then left, which gets decided by inL and inR, if inL > inR that subtree
// is empty and we go back and use same pIdx as its not decremented to see if its left subtree
TreeNode *util(vector<int> &inOrder, vector<int> &postOrder, unordered_map<int, int> &inOrderIndex, int inL, int inR,
               int &pIdx) {
    if (inL > inR) return NULL;

    TreeNode *root = new TreeNode(postOrder[pIdx]);
    int inIdx = inOrderIndex[postOrder[pIdx]];
    pIdx--;

    root->right = util(inOrder, postOrder, inOrderIndex, inIdx + 1, inR, pIdx);
    root->left = util(inOrder, postOrder, inOrderIndex, inL, inIdx - 1, pIdx);
    // when this call happens pIdx would have been decremented by the number of nodes in the right subtree
    return root;
}

TreeNode *Solution::buildTree(vector<int> &inOrder, vector<int> &postOrder) {
    unordered_map<int, int> inOrderIndex;  // its given that elements are distinct
    for (int i = 0; i < inOrder.size(); i++) {
        inOrderIndex[inOrder[i]] = i;
    }

    int pIdx = postOrder.size() - 1;
    return util(inOrder, postOrder, inOrderIndex, 0, inOrder.size() - 1, pIdx);
}