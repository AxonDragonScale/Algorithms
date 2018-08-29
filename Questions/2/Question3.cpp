int util(Node* root,int &min1,int &max1,int &max_ans)
{
    if(!root)
        return 0;
    int a=INT_MAX,b=INT_MIN,c=INT_MAX,d=INT_MIN;
    int l=util(root->left,a,b,max_ans);
    int r=util(root->right,c,d,max_ans);
    //cout<<root->data<<" "<<l<<" "<<r<<endl;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    if(l==-1 || r==-1)
        return -1;
    if(b>root->data || c<root->data)
        return -1;
    max1=max(d,root->data);
    min1=min(a,root->data);
    max_ans=max(max_ans,l+r+1);
    //cout<<"max_ans="<<max_ans<<endl;
    return l+r+1;
}
 
 
int largestBst(Node *root)
{
	//Your code here
	if(!root)
	    return 0;
	int min1,max1,max_ans=1;
	util(root,min1,max1,max_ans);
	return max_ans;
}