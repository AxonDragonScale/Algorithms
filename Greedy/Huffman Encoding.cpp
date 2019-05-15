
// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
// https://practice.geeksforgeeks.org/problems/huffman-encoding/0

// This is greedy because we assign codes with minimum length to characters that appear most frequently
// We first make a min priority queue and push all elements into it. Then we remove the two elements with minimum
// frequency and make a new element with frequency as the sum of their frequencies and make them its left and right
// child. All these internal nodes have no data, only leaf nodes have data.

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
using lli = long long int;

struct Node {
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char d, int f) {
        this->data = d;
        this->freq = f;
        left = NULL;
        right = NULL;
    }
};

// it has to be a class or a struct (if class, remember to make it public)
// function name has to be 'operator()'
struct Comparator {
    bool operator()(Node *a, Node *b) { return a->freq > b->freq; }
};

void printCodes(Node *root, string s) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        cout << s << " ";
    }

    printCodes(root->left, s + "0");
    printCodes(root->right, s + "1");
}

// function to decode an encoded string given a huffman tree
string decode(Node *root, string encodedData) {
    int n = encodedData.size();
    string ans = "";

    int i = 0;
    while (i < n) {
        Node *cur = root;
        while (cur->data == '-') {  // while not a leaf node
            if (encodedData[i++] == '0') {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        ans = ans + cur->data;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string allData;
        cin >> allData;
        int n = allData.size();

        priority_queue<Node *, vector<Node *>, Comparator> mh;  // MinHeap
        int temp;                                               // frequency
        for (int i = 0; i < n; i++) {
            cin >> temp;
            mh.push(new Node(allData[i], temp));
        }

        while (mh.size() != 1) {
            Node *min1 = mh.top();
            mh.pop();
            Node *min2 = mh.top();
            mh.pop();
            Node *node = new Node('-', min1->freq + min2->freq);  // '-' indicates internal nodes, no data
            node->left = min1;
            node->right = min2;
            mh.push(node);
        }

        printCodes(mh.top(), "");
        cout << endl;
    }

    return 0;
}