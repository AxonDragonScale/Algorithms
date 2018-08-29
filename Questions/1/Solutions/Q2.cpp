#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define INF INT_MAX-4
using namespace std;

int f,n,m;
char floors[100][1000][1000];
pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};

typedef struct node{
    int x,y;
}node;

int bfs(int fn)
{
    int dist[n][m], vis[n][m];
    queue<node> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(floors[fn][i][j]=='E')
            {
                dist[i][j] = 0;
                vis[i][j] = 1;
                q.push({i,j});
            }
            else
            {
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        for(auto p:dir)
        {
            int x = cur.x + p.first, y = cur.y + p.second;
            if(x<0||x>=n||y<0||y>=m)
                continue;
            if(floors[fn][x][y]=='O')
                continue;
            if(!vis[x][y] && dist[x][y]>dist[cur.x][cur.y] + 1)
            {
                dist[x][y] = dist[cur.x][cur.y] + 1;
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(floors[fn][i][j]=='P')
            {
                ans = max(ans,dist[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>f>>n>>m;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin>>floors[i][j][k];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<f;i++)
    {
        ans = bfs(i);
        if(ans!=INF)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}

