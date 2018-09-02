
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Link list Node  
// struct Node {
//     int data;
//     Node* next;
// }; 


Node* SortedMerge(Node* head1, Node* head2) {
    
    Node *head = new Node;  // dummy node
    Node *cur = head;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            cur->next = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;    
    }
    
    if(head1 != NULL) {
        cur->next = head1;
    }
    
    if(head2 != NULL) {
        cur->next = head2;
    }
    
    return head->next;
}