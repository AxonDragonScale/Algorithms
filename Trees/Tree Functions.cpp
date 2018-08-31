#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>

#define LN cout<<__LINE__<<endl

using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};


void levelOrderTraversal(Node *root) {
	if(root == NULL) {
		return;
	}

	queue<Node*> q;
	q.push(root);
	q.push(NULL);	// NULL will seperate different levels

	Node *cur;
	while(!q.empty()) {
		cur = q.front();
		q.pop();

		if(cur == NULL) {
			cout<<endl;
			if(!q.empty()) {	// Dont push a NULL after the last level NULL
				q.push(NULL);
			}
			continue;
		}

		cout<<cur->data<<" ";

		if(cur->left != NULL) {
			q.push(cur->left);
		}
		if(cur->right != NULL) {
			q.push(cur->right);
		}
	}
}


// levelOrderInsert method 1
// if you want to skip nodes, you can modify it to only make a new node if arr[i] != -1
Node *levelOrderInsert(int arr[], int n) {
	if(n == 0) {
		return NULL;
	}

	Node *root = new Node(arr[0]);
	queue< pair<Node*, int> > q;
	q.push({root, 0});

	Node *curNode;
	int curIdx;
	while(!q.empty()) {
		curNode = q.front().first;
		curIdx = q.front().second;
		q.pop();

		if(2*curIdx + 1 < n) {
			curNode->left = new Node(arr[2*curIdx + 1]);
			q.push({curNode, 2*curIdx + 1});
		}

		if(2*curIdx + 2 < n) {
			curNode->right = new Node(arr[2*curIdx + 2]);
			q.push({curNode, 2*curIdx + 2});
		}
	}

	return root;
}


// levelOrderInsert method 2
Node *levelOrderInsertAlternative(int arr[], int n) {
	if(n == 0) {
		return NULL;
	}

	Node *root = new Node(arr[0]);
	queue<Node*> q;
	q.push(root);
	int idx = 1;

	Node *cur;
	while(!q.empty()) {
		cur = q.front();
		q.pop();

		if(idx < n) {
			cur->left = new Node(arr[idx++]);
			q.push(cur->left);
		}

		if(idx < n) {
			cur->right = new Node(crr[idx++]);
			q.push(cur->right);
		}
	}

	return root;
}





int main() {

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	return 0;
}