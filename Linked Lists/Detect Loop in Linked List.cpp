
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

int detectloop(Node *head) {
    Node *slow, *fast;
    slow = fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return 1;
    }
    
    return 0;
}