#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
#define INF INT_MAX/2
using namespace std;

void dijkstra(vector<vector<pair<int,int>>> &g,int s,int dist[],int vis[])
{
    dist[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        for(auto ed:g[u])
        {
            int v,w;
            v=ed.second;
            w=ed.first;
            if(!vis[v] && dist[v]>dist[u]+w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,u,v;
    cin>>n;
    int road[n][n],rail[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>road[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>rail[i][j];
    }
    cin>>u>>v;
    u--,v--;
    vector<vector<pair<int,int>>> groad(n),grail(n),groad_rev(n),grail_rev(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(road[i][j]!=0)
            {
                groad[i].push_back({road[i][j],j});
                groad_rev[j].push_back({road[i][j],i});
            }
            if(rail[i][j]!=0)
            {
                grail[i].push_back({rail[i][j],j});
                grail_rev[j].push_back({rail[i][j],i});
            }
        }
    }
    int distroad[n],distroad_rev[n],distrail[n],distrail_rev[n],vis[n];
    for(int i=0;i<n;i++)
    {
        distroad[i] = INF;
        distroad_rev[i] = INF;
        distrail[i] = INF;
        distrail_rev[i] = INF;
        vis[i] = 0;
    }
    dijkstra(groad,u,distroad,vis);
    for(int i=0;i<n;i++)
        vis[i] = 0;
    dijkstra(grail,u,distrail,vis);
    for(int i=0;i<n;i++)
        vis[i] = 0;
    dijkstra(groad_rev,v,distroad_rev,vis);
    for(int i=0;i<n;i++)
        vis[i] = 0;
    dijkstra(grail_rev,v,distrail_rev,vis);
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(i==u || i==v)
            continue;
        if(distroad[i]!=INF && distrail_rev[i]!=INF)
            ans = min(ans,distroad[i] + distrail_rev[i]);
        if(distrail[i]!=INF && distroad_rev[i]!=INF)
            ans = min(ans,distrail[i] + distroad_rev[i]);
    }
    cout<<ans<<endl;
    return 0;
}

