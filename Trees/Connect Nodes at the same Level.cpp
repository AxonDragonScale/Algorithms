// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/?ref=self
// https://www.geeksforgeeks.org/connect-nodes-at-same-level/
// https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/
// https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/

struct Node {
    int data;
    Node *left, *right;
    Node *nextRight;  // This has garbage value in input trees
};

void connectNodesAtSameLevel(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    Node *cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == NULL) {
            if (!q.empty()) q.push(NULL);
            continue;
        } else {
            cur->nextRight = q.front();
            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
        }
    }
}
