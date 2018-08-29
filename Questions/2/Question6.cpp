class Solution {
public:
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> g(N);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0], v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> ans(N, 0), size(N, 1);
        dfs1(0, -1, g, ans, size);
        dfs2(0, -1, 0, N, g, ans, size);
        return ans;
    }
    void dfs1(int u, int par, vector<vector<int>> &g, vector<int> &ans, vector<int> &size)
    {
        for(int v:g[u])
        {
            if(v==par)
                continue;
            dfs1(v, u, g, ans, size);
            size[u] = size[u] + size[v];
            ans[u] = ans[u] + ans[v] + size[v];
        }
    }
    void dfs2(int u, int par, int parans, int N, vector<vector<int>> &g, vector<int> &ans, vector<int> &size)
    {
        ans[u] = ans[u] + parans + N - size[u];
        for(int v:g[u])
        {
            if(v==par)
                continue;
            dfs2(v, u, ans[u]-ans[v]-size[v], N, g, ans, size);
        }
    }
};