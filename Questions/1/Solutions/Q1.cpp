#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#define f first
#define s second
using namespace std;

int n, m;
vector<vector<pair<int,int>>> g;

int bfs_0_1()
{
	vector<int> dist(n, INT_MAX);
	vector<bool> vis(n, 0);
	dist[0] = 0;
	deque<int> q;
	q.push_back(0);
	while(!q.empty())
	{
		int u = q.front();
		q.pop_front();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(auto p:g[u])
		{
			int v = p.f, w = p.s;
			if(!vis[v] && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if(w==0)
					q.push_front(v);
				else
					q.push_back(v);
			}
		}
	}
	if(!vis[n-1])
		return -1;
	else
		return dist[n-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	g.resize(n);
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin>>u>>v;
		u--, v--;
		g[u].push_back({v, 0});
		g[v].push_back({u, 1});
	}
	cout<<bfs_0_1()<<endl;
	return 0;
}
