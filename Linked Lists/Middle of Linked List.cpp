
// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

// Bad Version
int getMiddle(Node *head) {
    if(head == NULL) return -1;
    
    int size = 0;
    Node *cur = head;
    while(cur != NULL) {
        cur = cur->next;
        size++;
    }
    
    cur = head;
    int mid = size/2;
    
    while(mid > 0) {
        cur = cur->next;
        mid--;
    }
    
    return cur->data;
}


// Good Version
// move fast pointer twice as fast as the slow pointer
int getMiddle(Node *head) {
	if(head == NULL) return -1;

	Node *slow, *fast;
	slow = fast = head;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
		    fast = fast->next;
		    slow =  slow->next;
		}
	}

	return slow->data;
}