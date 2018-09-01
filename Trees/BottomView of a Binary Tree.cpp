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

void bottomView(Node *root) {
   if(root == NULL) {
        return;
    }
    
    map<int, int> m;
    queue< pair<Node*, int> > q;
    q.push({root, 0});
    
    Node *cur; int d;
    while(!q.empty()) {
        cur = q.front().first;
        d = q.front().second;
        q.pop();
        
        m[d] = cur->data;
        
        if(cur->left != NULL) {
            q.push({cur->left, d-1});
        }
        if(cur->right != NULL) {
            q.push({cur->right, d+1});
        }
    }
    

    for(pair<int, int> i : m) {
        cout<<i.second<<" ";
    }
    cout<<endl;
}