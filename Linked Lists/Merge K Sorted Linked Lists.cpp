// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

struct Node {
    int data;
    Node *next;

    Node() {}
    Node(int data) : data(data), next(NULL) {}
};

Node *mergeTwoSortedLists(Node *head1, Node *head2) {
    Node *head = new Node;
    Node *cur = head;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            cur->next = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            head2 = head2->next;
        }

        cur = cur->next;
    }

    if (head1 != NULL) {
        cur->next = head1;
    }

    if (head2 != NULL) {
        cur->next = head2;
    }

    return head->next;
}

int main() {
    int k;  // no of linked lists
    cin >> k;

    vector<Node *> lists(k);

    for (int i = 0; i < k; i++) {
        int n;  // size of the linked list
        cin >> n;

        int temp;
        cin >> temp;
        lists[i] = new Node(temp);
        Node *cur = lists[i];
        for (int j = 1; j < n; j++) {
            cin >> temp;
            cur->next = new Node(temp);
            cur = cur->next;
        }

        // cout << "List " << i << " saved." << endl;
    }

    // cout << "All lists saved" << endl;

    k--;
    while (k != 0) {
        int i = 0, j = k;  // there are k lists to be merged

        while (i < j) {
            lists[i] = mergeTwoSortedLists(lists[i], lists[j]);  // merge 1st and last, 2nd and 2nd last, ...
            i++;
            j--;  // next pair

            if (i >= j) k = j;  // when all pairs are done, last list is at index j (because we just did j--)
        }
    }

    Node *cur = lists[0];
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}

// TODO : try minheap method