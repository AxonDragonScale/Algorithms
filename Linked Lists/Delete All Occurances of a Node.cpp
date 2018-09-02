
// https://practice.geeksforgeeks.org/problems/delete-keys-in-a-linked-list/1
// https://www.geeksforgeeks.org/delete-occurrences-given-key-linked-list/

// Recursive Version
Node* deleteAllOccurances(Node *head, int x) {
    if(head == NULL) return NULL;
    
    if(head->data == x && head->next == NULL) return NULL;
    
    head->next = deleteAllOccurances(head->next, x);
    if(head->data == x) {
        return head->next;
    } else {
        return head;
    }
}

// Iterative version
Node* deleteAllOccurances(Node *head, int x) {
    while(head != NULL && head->data == x) head = head->next;
    if(head == NULL) return NULL;
    
    Node *cur = head->next;
    Node *prev = head;
    while(cur != NULL) {
        if(cur->data == x) {
            prev->next = cur->next;
            cur = cur->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    
    return head;
}