// https://www.interviewbit.com/problems/reverse-link-list-ii/

// TODO : Write a more elegant version, check gfg for similar question and check interviewbit

// Reverse a linked list from position m to n. Do it in-place and in one-pass. For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
// Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

Node *reverseList(Node *head, int size) {
    if (size <= 1) return head;

    Node *prev, *next, *cur = head;
    for (int i = 0; i < size; i++) {
        next = cur->next;

        cur->next = prev;
        prev = cur;

        cur = next;
    }

    head->next = next;  // next of 1st element is now, the node after last element
    return prev;
}

Node *reverseSegment(Node *l, int start, int end) {
    if (start == end) return l;

    Node *dummy = new Node(-1);
    dummy->next = l;

    int idx = 1;
    Node *prev = dummy, *cur = l;
    while (idx < start) {
        prev = cur;
        cur = cur->next;
        idx++;
    }

    prev->next = reverseList(cur, end - start + 1);
    return dummy->next;
}

// Too complicated
ListNode *Solution::reverseBetween(ListNode *l, int start, int end) {
    if (start == end) return l;

    ListNode *headEnd, *tailStart, *revStart;

    ListNode *cur = l;
    if (start > 1) {
        for (int i = 1; i < start - 1; i++) {
            cur = cur->next;
        }
        headEnd = cur;
        revStart = cur->next;
        cur->next = NULL;
    } else {
        revStart = cur;
    }

    cur = revStart;
    for (int i = start; i < end; i++) {
        cur = cur->next;
    }
    tailStart = cur->next;
    cur->next = NULL;

    ListNode *prev = NULL, *next = revStart;
    cur = revStart;

    while (cur) {
        next = cur->next;

        cur->next = prev;
        prev = cur;

        cur = next;
    }

    ListNode *ans;
    if (start > 1) {
        ans = l;
        headEnd->next = prev;
    } else {
        ans = prev;
    }

    revStart->next = tailStart;

    return ans;
}
