// https://www.interviewbit.com/problems/k-reverse-linked-list/
// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

ListNode* Solution::reverseList(ListNode* l, int k) {
    ListNode* cur = l;
    ListNode *prev = NULL, *next = l;

    for (int i = 0; i < k; i++) {
        if (!cur) break;
        next = cur->next;

        cur->next = prev;
        prev = cur;

        cur = next;
    }

    if (next) l->next = reverseList(next, k);  // l is now the last node of the group
    return prev;
}

// https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/ -> TODO (using stack)