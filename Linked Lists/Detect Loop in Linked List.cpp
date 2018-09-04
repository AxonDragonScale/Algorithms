
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


// TODO
// Detect and Remove Loop - Do this (understand all methods), its good.
// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

void removeTheLoop(Node *head) {
    // Find if loop exists (slow/fast will become a node in the loop)
    Node *slow, *fast;
    slow = fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) break;
    }
    
    if(fast == NULL) return;
    
    // Find Length of loop
    int loopLength = 1;
    Node *nodeInLoop = slow;
    Node *cur = nodeInLoop->next;
    while(cur != nodeInLoop) {
        cur = cur->next;
        loopLength++;
    }
    
    // Make fast k steps ahead from start(/slow)
    // move them forward at same speed till their next are the same
    slow = fast = head;
    for(int i = 0; i<loopLength; i++) {
        fast = fast->next;
    }
    
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = NULL;
}