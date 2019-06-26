// https://www.interviewbit.com/problems/rotate-list/

// Given a list, rotate the list to the right by k places, where k is non-negative. For example:
// Given 1->2->3->4->5->NULL and k = 2, return 4->5->1->2->3->NULL.

ListNode* Solution::rotateRight(ListNode* l, int k) {
    int len = 0;
    ListNode* temp = l;
    while (temp) {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0) return l;

    ListNode *slow = l, *fast = l, *head;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    head = slow->next;

    fast->next = l;
    slow->next = NULL;

    return head;
}