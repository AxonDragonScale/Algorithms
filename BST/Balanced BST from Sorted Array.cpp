#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node *sortedArrayToBalancedBST(const vector<int> &arr, int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBalancedBST(arr, l, mid - 1);
    root->right = sortedArrayToBalancedBST(arr, mid + 1, r);

    return root;
}

void printInOrder(Node *root) {
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node *root = sortedArrayToBalancedBST(arr, 0, n - 1);
    printInOrder(root);

    return 0;
}
