
// https://www.interviewbit.com/problems/palindrome-list/
// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

ListNode *reverse(ListNode *A) {
    ListNode *cur = A;
    ListNode *prev = NULL, *next;

    while (cur) {
        next = cur->next;

        cur->next = prev;
        prev = cur;

        cur = next;
    }

    return prev;
}

int Solution::lPalin(ListNode *A) {
    int len = 0;
    ListNode *temp = A;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    temp = A;
    if (len % 2 == 0) {
        for (int i = 0; i < len / 2; i++) {
            temp = temp->next;
        }
    } else {
        for (int i = 0; i < len / 2 + 1; i++) {
            temp = temp->next;
        }
    }

    temp = reverse(temp);
    for (int i = 0; i < len / 2; i++) {
        if (A->val != temp->val) {
            return 0;
        }

        A = A->next;
        temp = temp->next;
    }

    return 1;
}