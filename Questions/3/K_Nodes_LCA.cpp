    #include <iostream>
    #include <stdlib.h>
    #include <vector>
    #include <utility>
    #include <climits>
    using namespace std;
     
    struct Node{
    	int data;
    	struct Node *left;
    	struct Node *right;
    };
     
    struct Node *newnode(int data){
    	struct Node *temp = new Node();
    	temp->data = data;
    	temp->left = NULL;
    	temp->right = NULL;
    	return temp;
    }
     
    struct Node *insert(struct Node *root,int data){
        if(root == NULL)
        	return newnode(data);
     
        if(data < root->data)
           root->left = insert(root->left,data);
     
        if(data > root->data)
        	root->right = insert(root->right,data);
        return root;
    }
     
    struct Node *lca(struct Node *root,int n1,int n2){
         if(root == NULL)
            return root;
         if(root->data >n1 && root->data >n2)
            return lca(root->left,n1,n2);
         if(root->data<n1 && root->data<n2)
            return lca(root->right,n1,n2);
         return root;
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int n,k,data;
    	cin>>n>>k;
    	Node *root = NULL;
    	for(int i=0;i<n;i++){
    		cin>>data;
    		root = insert(root,data);
    	}
     
    	int min_node = INT_MAX;
    	int max_node = INT_MIN;
     
    	for(int i=0;i<k;i++){
    		cin>>data;
    		min_node = min(min_node,data);
    		max_node = max(max_node,data);
    	}
        
        Node *ans = lca(root,min_node,max_node);
        if(ans)
        	cout<<ans->data<<endl;
        else
        	cout<<"-1"<<endl;
    }