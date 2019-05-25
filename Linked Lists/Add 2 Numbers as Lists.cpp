//  https://www.interviewbit.com/problems/add-two-numbers-as-lists/

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // We can also construct the two numbers, add them and then deconstruct to list

    int carry = 0;
    ListNode* ans = new ListNode(-1);
    ListNode* cur = ans;
    while (A || B || carry) {
        int sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;  // Put the brackets

        cur->next = new ListNode(sum % 10);
        carry = sum / 10;

        cur = cur->next;
        if (A) A = A->next;
        if (B) B = B->next;
    }

    return ans->next;
}

// This is just bigger version of above code
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // We can also construct the two numbers, add them and then deconstruct to list

    int carry = 0;
    ListNode* ans = new ListNode(-1);
    ListNode* cur = ans;
    while (A && B) {
        int d = A->val + B->val + carry;

        cur->next = new ListNode(d % 10);
        carry = d / 10;

        cur = cur->next;
        A = A->next;
        B = B->next;
    }

    while (A) {
        int d = A->val + carry;

        cur->next = new ListNode(d % 10);
        carry = d / 10;

        cur = cur->next;
        A = A->next;
    }

    while (B) {
        int d = B->val + carry;

        cur->next = new ListNode(d % 10);
        carry = d / 10;

        cur = cur->next;
        B = B->next;
    }

    if (carry != 0) {
        cur->next = new ListNode(carry);
    }

    return ans->next;
}
