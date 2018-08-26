// 0-1 BFS finds the shortest path from src to all vertices

#include <iostream>
#include <deque>
#include <vector>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int main() {

	int V, E, u, v, w, src;
	cin>>V>>E;
	deque< pair<int, int> > adj[V];
	// adj[i] stores pairs with vertex as first element and weight of as second

	for(int i = 0; i<E; i++) {
		cin>>u>>v>>w;
		adj[u].push_back({v,w});	// Assuming undirected graph
		adj[v].push_back({u,w});
	}

	cin>>src;

	deque<int> dist(V, INT_MAX);
	deque<int> queue;

	dist[src] = 0;
	queue.push_back(src);

	int node;
	while(!queue.empty()) {
		node = queue.front();
		queue.pop_front();

		for(pair<int, int> i : adj[node]) {
			// If the distance of i.first from s is more than distance of node (i.first's parent) + weight of edge from node to i
			if(dist[i.first] > dist[node] + i.second) {	
				dist[i.first] = dist[node] + i.second;

				// we only push the i.first node if it has shorter distance 
				// push i in front of queue if it has 0 weight else push it at the end
				if(i.second == 0) {
					queue.push_front(i.first);
				} else {
					queue.push_back(i.first);
				}
			}
		}
	}

	for(int i : dist) {
        cout<<i<<" ";
    }
    cout<<endl;

	return 0;
}