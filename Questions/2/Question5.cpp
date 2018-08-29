#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
vector<vector<int>> g;
vector<int> A;
unordered_map<int,int> cnt;
int k;
long long ans;
 
void dfs(int par, int u, int pxor)
{
	int npxor = pxor^A[u];
	ans += cnt[npxor^k];
	cnt[npxor]++;
	for(int v:g[u])
	{
		if(v!=par)
			dfs(u, v, npxor);
	}
	cnt[npxor]--;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n>>k;
	g.resize(n);
	A.resize(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=1;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		tmp--;
		g[i].push_back(tmp);
		g[tmp].push_back(i);
	}
	ans = 0;
	cnt[0]++;
	dfs(-1, 0, 0);
	cout<<ans<<endl;
	return 0;
}