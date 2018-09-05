
// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int key) {
        data = key;
        left = NULL;
        right = NULL;
    }
};

int t, n;
int pre[1000];

// there should be no smaller element after the next greater element
bool canRepresentBST(int pre[], int n) {
    stack<int> s;
    
    int curRoot = INT_MIN;
    for(int i = 0; i<n; i++) {
        // pre[i-1] was the next greater for curRoot
        // so pre[i] should not be smaller than curRoot
        if(pre[i] < curRoot) {  
            return false;
        }
        
        // if pre[i] is on right of s.top()
        // till pre[i] is the next greater for s.top()
        while(!s.empty() && pre[i] > s.top()) {
            curRoot = s.top();
            s.pop();
        }
        
        s.push(pre[i]);
    }
    return true;
}

Node* constructBST(int pre[], int n) {
    stack<Node*> s;
    
    Node *root = new Node(pre[0]);
    s.push(root);
    
    Node *curRoot;
    for(int i = 1; i<n; i++) {
        
        curRoot = NULL;
        while(!s.empty() && pre[i] > s.top()->data) {
            curRoot = s.top();
            s.pop();
        }
        
        if(curRoot == NULL) {
            // pre[i] is smaller than s.top()
            s.top()->left = new Node(pre[i]);
            s.push(s.top()->left);
        } else {
            curRoot->right = new Node(pre[i]);
            s.push(curRoot->right);
        }
    }
    
    return root;
}

void preOrder(Node *root) {
    if(root == NULL) return;

    preOrder(root->left);
    preOrder(root->right);    
    cout<<root->data<<" ";
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    for(int i = 0; i<n; i++) {
	        cin>>pre[i];
	    }
	    
	    if(!canRepresentBST(pre, n)) {
	        cout<<"NO"<<endl;
	        continue;
	    }
	    
	    Node *root = constructBST(pre, n);
	    preOrder(root);
	    cout<<endl;
	}
	
	return 0;
}
