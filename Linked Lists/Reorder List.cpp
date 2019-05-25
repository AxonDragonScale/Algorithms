// https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *l) {
    ListNode *cur = l;
    ListNode *prev = NULL, *next;

    while (cur) {
        next = cur->next;

        cur->next = prev;
        prev = cur;

        cur = next;
    }

    return prev;
}

ListNode *Solution::reorderList(ListNode *l) {
    ListNode *cur = l;
    int len = 0;
    while (cur) {
        cur = cur->next;
        len++;
    }

    ListNode *temp = l;
    if (len % 2 == 0) {
        for (int i = 0; i < len / 2; i++) {
            temp = temp->next;
        }
    } else {
        for (int i = 0; i < len / 2 + 1; i++) {
            temp = temp->next;
        }
    }

    ListNode *l1 = l;
    ListNode *l2 = reverse(temp);
    ListNode *ans = new ListNode(-1);

    cur = ans;
    for (int i = 0; i < len / 2; i++) {
        if (l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }

        if (l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }

    if (len % 2 == 1) {
        cur->next = l1;
        cur = cur->next;
    }

    cur->next = NULL;

    return ans->next;
}
