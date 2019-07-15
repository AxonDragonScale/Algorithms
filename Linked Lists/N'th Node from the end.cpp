// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?ref=self

int getNthFromLast(Node *head, int n) {
    Node *temp, *cur;
    temp = cur = head;

    int count = 0;
    while (cur != NULL) {
        cur = cur->next;
        count++;

        if (count > n) {
            temp = temp->next;
        }
    }

    if (count >= n)  // return -1 if the number of nodes is less than n
        return temp->data;
    else
        return -1;
}