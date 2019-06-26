// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

// Given a sorted linked list, delete all duplicates such that each element appear only once. For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

ListNode* Solution::deleteDuplicates(ListNode* l) {
    if (l == NULL) return l;

    ListNode* temp = l;
    while (temp->next) {
        if (temp->next->val == temp->val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }

    return l;
}

// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
// original list. For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

ListNode* Solution::deleteDuplicates(ListNode* l) {
    if (l == NULL) return l;

    ListNode *temp = l, *dummy = new ListNode(-1);
    ListNode* ans = dummy;

    while (temp) {
        if (temp->next && temp->next->val == temp->val) {
            while (temp->next && temp->next->val == temp->val) {
                temp = temp->next;
            }
            temp = temp->next;
        } else {
            dummy->next = temp;

            temp = temp->next;
            dummy = dummy->next;
        }
    }

    dummy->next = NULL;
    return ans->next;
}