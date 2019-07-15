
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// Reverse a Linked List

// Linked List Node structure
// struct Node  {
//  int data;
//  Node *next;
// }

// Should reverse list and return new head.
Node *reverse(Node *head) {
    Node *cur = head;
    Node *next, *prev;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Reverse a Doubly Linked List
Node *reverse(Node *head) {
    Node *cur = head;

    while (cur->next != NULL) {
        swap(cur->next, cur->prev);
        cur = cur->prev;
    }

    swap(cur->next, cur->prev);
    return cur;
}