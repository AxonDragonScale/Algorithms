#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

typedef struct edge{
    int v,w;
}edge;

auto comp = [](edge e1, edge e2){return e1.w>e2.w;};

vector<vector<edge>> g;
vector<int> vis, dist;

void dijkstra(int n)
{
    priority_queue<edge, vector<edge>, decltype(comp)> pq(comp);
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u = pq.top().v;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        if(u==3*n-1)
            break;
        for(edge e:g[u])
        {
            if(!vis[e.v] && dist[e.v] > dist[u] + e.w)
            {
                dist[e.v] = dist[u] + e.w;
                pq.push({e.v, dist[e.v]});
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, a, b;
    unordered_set<int> seta, setb;
    cin>>n>>m>>a>>b;
    g.resize(3*n);
    vis.resize(3*n, 0);
    dist.resize(3*n, INT_MAX/2);
    for(int i=0;i<a;i++)
    {
        int tmp;
        cin>>tmp;
        g[tmp].push_back({tmp+n,0});
        seta.insert(tmp);
    }
    for(int i=0;i<b;i++)
    {
        int tmp;
        cin>>tmp;
        g[tmp+n].push_back({tmp+2*n,0});
        setb.insert(tmp);
    }
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        g[u+n].push_back({v+n,w});
        g[v+n].push_back({u+n,w});
        g[u+2*n].push_back({v+2*n,w});
        g[v+2*n].push_back({u+2*n,w});
    }
    dijkstra(n);
    cout<<dist[3*n-1]<<endl;
    return 0;
}
