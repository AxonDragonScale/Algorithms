// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
// Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then
// right to left for the next level and alternate between).

vector<vector<int>> zigzagLevelOrder(Node *root) {
    vector<vector<int>> ans;
    vector<int> cur;

    stack<Node *> ltr, rtl;
    ltr.push(root);

    Node *temp;
    while (!ltr.empty() || !rtl.empty()) {
        cur.clear();
        while (!ltr.empty()) {
            temp = ltr.top();
            ltr.pop();
            cur.push_back(temp->val);
            if (temp->left) rtl.push(temp->left);
            if (temp->right) rtl.push(temp->right);
        }
        if (!cur.empty()) ans.push_back(cur);

        cur.clear();
        while (!rtl.empty()) {
            temp = rtl.top();
            rtl.pop();
            cur.push_back(temp->val);
            if (temp->right) ltr.push(temp->right);
            if (temp->left) ltr.push(temp->left);
        }
        if (!cur.empty()) ans.push_back(cur);
    }

    return ans;
}
