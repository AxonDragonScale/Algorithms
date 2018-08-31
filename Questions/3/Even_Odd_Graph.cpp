#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define f first
#define s second
using namespace std;

int n, m;
vector<vector<pair<int,int>>> g_even, g_odd;

struct node
{
    int u, odd, dist;
};

auto comp = [](node &a, node &b){ return a.dist > b.dist; };

int dijkstra(int src, int dest)
{
    vector<vector<bool>> vis(n, vector<bool>(2, 0));
    vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
    priority_queue<node, vector<node>, decltype(comp)> q(comp);
    dist[src][0] = 0;//even
    dist[src][1] = 0;//odd
    q.push({src, 0, 0});
    q.push({src, 1, 0});
    while(!q.empty())
    {
        int u = q.top().u, odd = q.top().odd;
        q.pop();
        if(vis[u][odd])
            continue;
        vis[u][odd] = 1;
        if(u==dest)
            return dist[u][odd];
        if(!odd)//even
        {
            for(auto p:g_odd[u])
            {
                int v = p.f, w = p.s;
                if(!vis[v][!odd] && dist[v][!odd] > dist[u][odd] + w)
                {
                    dist[v][!odd] = dist[u][odd] + w;
                    q.push({v, !odd, dist[v][!odd]});
                }
            }
        }
        else//odd
        {
            for(auto p:g_even[u])
            {
                int v = p.f, w = p.s;
                if(!vis[v][!odd] && dist[v][!odd] > dist[u][odd] + w)
                {
                    dist[v][!odd] = dist[u][odd] + w;
                    q.push({v, !odd, dist[v][!odd]});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    g_even.resize(n);
    g_odd.resize(n);
    for(int i=0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        if(w%2==0)
        {
            g_even[u].push_back({v, w});
            g_even[v].push_back({u, w});
        }
        else
        {
            g_odd[u].push_back({v, w});
            g_odd[v].push_back({u, w});
        }
    }
    int src, dest;
    cin>>src>>dest;
    src--, dest--;
    cout<<dijkstra(src, dest)<<endl;
    return 0;
}