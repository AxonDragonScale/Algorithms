
// https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1

// struct Node{
//     int key;
//     Node *left;
//     Node *right;
// }

/* Function to print corner node at each level */
void printCorner(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    Node* cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        
        if(cur == NULL && !q.empty() && q.front() != NULL) {
            cout<<q.front()->key<<" ";
            q.push(NULL);
            continue;
        }
        
        if(!q.empty() && q.front() == NULL) {
            cout<<cur->key<<" ";
        }
        
        if(cur != NULL && cur->left != NULL) {
            q.push(cur->left);
        }
        if(cur != NULL && cur->right != NULL) {
            q.push(cur->right);
        }
    }
}