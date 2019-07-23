// https://www.geeksforgeeks.org/print-binary-tree-vertical-order/ -> bad
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
// https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/

void verticalTaversal(Node *root) {
    if (root == NULL) {
        return;
    }

    unordered_map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});  // second is horizontal distance

    int minD = 0, maxD = 0;
    while (!q.empty()) {
        Node *cur = q.front().first;
        int d = q.front().second;
        q.pop();

        minD = min(minD, d);
        maxD = max(maxD, d);

        m[d].push_back(cur->data);

        if (cur->left) q.push({cur->left, d - 1});
        if (cur->right) q.push({cur->right, d + 1});
    }

    for (int d = minD; d <= maxD; d++) {
        for (int i : m[d]) cout << i << " ";
    }
    cout << endl;
}