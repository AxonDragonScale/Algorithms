// https://www.interviewbit.com/problems/intersection-of-linked-lists/

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int l1 = 0, l2 = 0;

    ListNode* temp = A;
    while (temp != NULL) {  // find length of A
        temp = temp->next;
        l1++;
    }

    temp = B;
    while (temp != NULL) {  // find length of B
        temp = temp->next;
        l2++;
    }

    ListNode* temp1 = A;
    ListNode* temp2 = B;

    // Take |l1 - l2| steps on the longer linked list
    if (l1 > l2) {
        for (int i = 0; i < l1 - l2; i++) {
            temp1 = temp1->next;
        }
    } else if (l1 < l2) {
        for (int i = 0; i < l2 - l1; i++) {
            temp2 = temp2->next;
        }
    }

    // traverse both till they reach intersection or one ends
    while (temp1 != NULL && temp2 != NULL && temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != temp2) return NULL;
    return temp1;
}