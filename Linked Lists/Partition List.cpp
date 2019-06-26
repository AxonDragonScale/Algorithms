// https://www.interviewbit.com/problems/partition-list/

// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
// equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
// For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

ListNode *Solution::partition(ListNode *l, int k) {
    ListNode *cur = l;
    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-1);

    ListNode *t1 = l1, *t2 = l2;

    while (cur) {
        if (cur->val < k) {
            l1->next = cur;
            l1 = l1->next;
        } else {
            l2->next = cur;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    l2->next = NULL;
    l1->next = t2->next;
    return t1->next;
}