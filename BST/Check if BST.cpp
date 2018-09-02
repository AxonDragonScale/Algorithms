
// https://practice.geeksforgeeks.org/problems/check-for-bst/1

bool isBSTUtil(Node *root, int min, int max) {
    if(root == NULL) return true;
    
    if(root->data < min) return false;
    if(root->data > max) return false;
    
    return isBSTUtil(root->left, min, root->data-1) &&
            isBSTUtil(root->right, root->data+1, max);
}   
   
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


// method 2
bool isBST(Node *root, Node *l = NULL, Node *r = NULL) {
	if(root == NULL) return true;

	if(l != NULL && l->data > root->data)	return false;
	if(r != NULL && r->data < root->data)	return false;

	return isBST(root->left, l, root) && isBST(root->right, root, r);
}	