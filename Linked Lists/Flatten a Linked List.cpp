// https://www.geeksforgeeks.org/flattening-a-linked-list/

// Flatten the linked list such that all right pointers are empty and the down pointers make a sorted list

struct Node {
    int data;
    struct Node *next;
    struct Node *down;
};

Node *merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    Node *ans;
    if (a->data < b->data) {
        ans = a;
        ans->down = merge(a->down, b);
    } else {
        ans = b;
        ans->down = merge(a, b->down);
    }

    return ans;
}

Node *flatten(Node *root) {
    if (!root || !root->next) return root;
    return merge(root, flatten(root->next));  // flatten all lists after root and then merge with root
}