// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

// Given a linked list, remove the nth node from the end of list and return its head.
// For example, Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// If n is greater than the size of the list, remove the first node of the list.

ListNode* Solution::removeNthFromEnd(ListNode* l, int n) {
    ListNode *slow = l, *fast = l;
    for (int i = 0; i < n; i++) {
        if (fast) fast = fast->next;
    }

    if (!fast || !fast->next) return l->next;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return l;
}