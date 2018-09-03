
// https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1
// https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

// Structure of a node is as following
// struct Node
// {
//      int data;
//      struct Node* left;
//      struct Node* right;
// };


// Function should print all the ancestor of the target node
bool printAncestorsUtil(Node *root, int target) {
    if(root == NULL) return false;
    if(root->data == target) return true;
    
    if(printAncestorsUtil(root->left, target) || printAncestorsUtil(root->right, target)) {
        cout<<root->data<<" ";
        return true;
    } else {
        return false;
    }
}

bool printAncestors(Node *root, int target) {
    printAncestorsUtil(root, target);
    cout<<endl;
}