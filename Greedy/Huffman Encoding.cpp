
// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
// https://practice.geeksforgeeks.org/problems/huffman-encoding/0

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define LN cout<<__LINE__<<endl
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
    bool operator()(Node *a, Node *b) { 	
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string s) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        cout<<s<<" ";
    }
    
    printCodes(root->left, s+"0");
    printCodes(root->right, s+"1");
}

int main() {

	int t;
	cin>>t;
	while(t--) {
	    string allData;
	    cin>>allData;
	    int n = allData.size();
	    
	    priority_queue<Node*, vector<Node*>, Comparator> mh; // MinHeap
	    int temp;
	    for(int i = 0; i<n; i++) {
	        cin>>temp;
	        mh.push(new Node(allData[i], temp));
	    }
	    
	    while(mh.size() != 1) {
	        Node *min1 = mh.top(); mh.pop();
	        Node *min2 = mh.top(); mh.pop();
	        Node *node = new Node('-', min1->freq + min2->freq);
	        node->left = min1;
	        node->right = min2;
	        mh.push(node);
	    }
	    
	    printCodes(mh.top(), "");
	    cout<<endl;
	}

	return 0;
}