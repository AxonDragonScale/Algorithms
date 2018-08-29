vector<vector<int> >g;
 
int dfs(int u,long &max1)
{
    if(g[u].size()==0)
        return 1;
    long max2=0,max3=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        int x=dfs(v,max1);
        if(x>=max2)
        {
            max3=max2;
            max2=x;
        }
        else if(x<max2&&x>max3)
            max3=x;
    }
    max1=max(max1,max2+max3);
    return max2+1;
}
 
int Solution::solve(vector<int> &A) {
    int n=A.size(),root;
    g.clear();
    g.resize(n);
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
        {
            root=i;
            continue;
        }
        g[A[i]].push_back(i);
    }
    long max1=0;
    dfs(root,max1);
    return max1;
}