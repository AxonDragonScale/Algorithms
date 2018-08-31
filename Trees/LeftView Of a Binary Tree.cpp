
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


// do a BFS/level order and print first node of each level
void leftView(Node *root) {
   if(root == NULL) {
       return;
   } 
    
   queue<Node*> q;
   q.push(NULL);
   q.push(root);
   
   Node *cur;
   while(!q.empty()) {
       cur = q.front();
       q.pop();
       
       if(cur == NULL && !q.empty()) {
           cout<<q.front()->data<<" ";
           q.push(NULL);
           continue;
       }
       
       if(cur != NULL && cur->left != NULL) {
           q.push(cur->left);
       }
       if(cur != NULL && cur->right != NULL) {
           q.push(cur->right);
       }
   }
   cout<<endl;
}


// can be done using DFS as well
void leftViewUtil(Node *root, int h, int &minH) {
	if(root == NULL) {
		return;
	}

	if(h > minH) {	// we reached a new level
		minH = h;
		cout<<root->data;
	}

	leftViewUtil(root->left, h+1, minH);
	leftViewUtil(root->right, h+1, minH);
}

void leftView(Node *root) {
	int minH = -1;

	leftViewUtil(root, 0, minH);
	cout<<endl;
}

