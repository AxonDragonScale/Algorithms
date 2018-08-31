#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

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


// Find the size of the tree
int size(Node *root) {
	if(root == NULL) {
		return 0;
	}

	return 1 + size(root->left) + size(root->right);
}


// Find the height of the tree
int height(Node *root) {
	if(root == NULL) {
		return 0;
	}

	return 1 + max(height(root->left), height(root->right));
}


// Find the depth of the node which had key
int depth(Node *root, int key) {
	if(root == NULL) {
		return -1;
	}

	if(root->data == key) {
		return 0;
	}

	int dLeft = depth(root->left, key);
	int dRight = depth(root->right, key);

	if(dLeft != -1) return 1 + dLeft;
	if(dRight != -1) return 1 + dRight;
	return -1;
}


// Find the number of leaf nodes in the tree
int noOfLeafNodes(Node *root) {
	if(root == NULL) {
		return 0;
	}

	if(root->left == NULL && root->right == NULL) {
		return 1;
	} else {
		return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
	}
}


// Check if two trees are identical
bool isIdentical(Node *root1, Node *root2) {
	if(root1 == NULL && root2 == NULL) {
		return true;
	} else if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) {
		return false; 
	} else if(root1->data == root2->data) {
		return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
	}
}


// Check if 2 trees are mirrors of each other
bool isMirror(Node *root1, Node *root2) {
	if(root1 == NULL && root2 == NULL) {
		return true;
	} else if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) {
		return false; 
	} else if(root1->data == root2->data) {
		return isIdentical(root1->left, root2->right) && isIdentical(root1->right, root2->left);
	}
}


// Check if the tree is balanced
bool isBalanced(Node *root) {
	if(root == NULL) {
		return true;
	} 

	int hLeft = height(root->left);
	int hRight = height(root->right);

	return abs(hLeft - hRight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}


// diameter is number of nodes in the longest path between any 2 leaf nodes in the tree
int diameter(Node *root) {
	if(root == NULL) {
		return 0;
	}

	hLeft = height(root->left);
	hRight = height(root->right);

	return max(1 + hLeft + hRight, max(diameter(root->left), diameter(root->right)));
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