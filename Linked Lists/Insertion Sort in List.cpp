// https://www.interviewbit.com/problems/insertion-sort-list/

ListNode* Solution::insertionSortList(ListNode* l) {
    if (l == NULL) return l;

    ListNode* dummy = new ListNode(INT_MIN);
    dummy->next = l;

    ListNode *i = dummy, *j = dummy, *temp;
    while (i->next) {
        if (i->val < i->next->val) {  // only need to sort if current (i->next) is less than prev (i)
            i = i->next;
            continue;
        }

        j = dummy;  // find j->next thats greater than i->next
        while (j->next && j->next->val < i->next->val) {
            j = j->next;
        }

        //  insert i->next between j and j->next
        temp = i->next->next;

        i->next->next = j->next;
        j->next = i->next;

        i->next = temp;
    }

    return dummy->next;
}