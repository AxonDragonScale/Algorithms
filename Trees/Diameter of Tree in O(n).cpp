
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/

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

// We can calculate the diameter in O(n) by doing it while height of the tree is being calculated

int height(Node *root, int &theDiameter) {
    if(root == NULL) {
        return 0;
    }
    
    int hLeft = height(root->left, theDiameter);
    int hRight = height(root->right, theDiameter);
    
    theDiameter = max(theDiameter, 1 + hLeft + hRight);
    
    return 1 + max(hLeft, hRight);
}

int diameter(Node* root) {
    int theDiameter = INT_MIN;
    height(root, theDiameter);
    
    return theDiameter;
}