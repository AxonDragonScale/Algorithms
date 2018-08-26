// Given a directed graph and a source node and destination node,
// we need to find how many edges we need to reverse in order to
// make at least 1 path from source node to destination node.

// https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/

// Make all initial edges have weight zero and add reverse edge for every edge of weight 1.
// Use dijkstra's shortest path [O(nlogn)] or 0-1 BFS [O(n)] to find shortest path.
// Weight of the shortest path is the answer.

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {

	int V, E, u, v, s, d;
	cin>>V>>E;
	deque< pair<int, int> > adj[V]; 	//adjacency list 
	// adj[i] stores pairs with vertex as first element and weight of as second

	for(int i = 0; i<E; i++) {
		cin>>u>>v;
		adj[u].push_back({v, 0});	// from u to v with weight 0
		adj[v].push_back({u, 1});   // reverse edge with weight 1
	}

	cin>>s>>d;

	// ZeroOneBFS
	deque<int> dist(V, INT_MAX);
	deque<int> queue;

	queue.push_back(s);
	dist[s] = 0; //stores distance of each node from s

	int node;
	while(!queue.empty()) {
		node = queue.front();
		queue.pop_front();

		for(pair<int, int> i : adj[node]) {
			if(dist[i.first] > dist[node] + i.second) {
				// If the distance of i.first from s is more than distance of node (i.first's parent) + weight of edge from node to i
				dist[i.first] = dist[node] + i.second;

				// push i in front of queue if it has 0 weight else push it at the end
				if(i.second == 0) {
					queue.push_front(i.first);
				} else {
					queue.push_back(i.first);
				}
			}
		}
	}

	cout<<dist[d]<<endl;	// weight of shortest path is the min no. of reversals

	return 0;
}