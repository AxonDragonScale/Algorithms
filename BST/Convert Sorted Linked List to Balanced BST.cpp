// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

TreeNode* Solution::sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return new TreeNode(head->val);

    ListNode *slow = head, *fast = head, *prev;
    while (fast) {
        fast = fast->next;
        if (fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
    }

    TreeNode* root = new TreeNode(slow->val);
    if (prev) prev->next = NULL;                // cut list before mid
    root->left = sortedListToBST(head);         // left half of list (before mid)
    root->right = sortedListToBST(slow->next);  // right half

    return root;
}