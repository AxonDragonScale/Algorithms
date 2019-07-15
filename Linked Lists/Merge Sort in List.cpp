// https://www.interviewbit.com/problems/sort-list/

// ListNode *mergeTwoSortedLists(ListNode *a, ListNode *b) {  // a and b wont be null so no need to check
//     ListNode *dummy, *ans;  // not making a dummy with -1 bcoz that would take memory, total logn times
//     if (a->val < b->val) {
//         dummy = a;
//         a = a->next;
//     } else {
//         dummy = b;
//         b = b->next;
//     }
//     ans = dummy;

//     while (a && b) {
//         if (a->val < b->val) {
//             dummy->next = a;
//             a = a->next;
//         } else {
//             dummy->next = b;
//             b = b->next;
//         }
//         dummy = dummy->next;
//     }

//     if (a) dummy->next = a;
//     if (b) dummy->next = b;

//     return ans;
// }

ListNode *mergeTwoSortedLists(ListNode *a, ListNode *b) {
    if (!a) return b;
    if (!b) return a;

    ListNode *ans;
    if (a->data < b->data) {
        ans = a;
        ans->next = mergeTwoSortedLists(a->next, b);
    } else {
        ans = b;
        ans->next = mergeTwoSortedLists(a, b->next);
    }

    return ans;
}

ListNode *Solution::sortList(ListNode *l) {
    if (!l || !l->next) return l;
    if (!l->next->next) {
        if (l->val >= l->next->val) {
            swap(l->val, l->next->val);
        }
        return l;
    }

    ListNode *slow = l, *fast = l->next, *r;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    r = slow->next;
    slow->next = NULL;

    l = sortList(l);
    r = sortList(r);

    return mergeTwoSortedLists(l, r);
}
