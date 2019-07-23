// Question (similar not same)
// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/?ref=self
// https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

// Using two stacks
void spiralTraversal(Node *root) {
    if (root == NULL) return;

    stack<Node *> RTL, LTR;
    RTL.push(root);

    Node *cur;
    while (!RTL.empty() || !LTR.empty()) {
        while (!RTL.empty()) {
            cur = RTL.top();
            RTL.pop();

            cout << cur->data << " ";
            if (cur->right) LTR.push(cur->right);  // push in reverse order
            if (cur->left) LTR.push(cur->left);
        }

        while (!LTR.empty()) {
            cur = LTR.top();
            LTR.pop();

            cout << cur->data << " ";
            if (cur->left) RTL.push(cur->left);
            if (cur->right) RTL.push(cur->right);
        }
    }
}
