#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Graph {
public:
	int V;
	deque<int> *adj;

	Graph(int V) {
		this->V = V;
		adj = new deque<int>[V];
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}


	void DFSutil(int v, vector<bool> &visited) {	//Dont forget the '&'
		visited[v] = true;
		cout<<v<<" ";		// dont output this when finding mother vertex

		for(int i : adj[v]){
			if(!visited[i]) {
				DFSutil(i,visited);
			}
		}
	}

	void DFS(int v) {
		vector<bool> visited(V,false);
		
		DFSutil(v, visited);
	}

	void DFSIterative(int v) {
		vector<bool> visited(V,false);

		deque<int> stack;
		stack.push_back(v);

		while(!stack.empty()) {
			v = stack.back();
			stack.pop_back();

			if(!visited[v]) {
				visited[v] = true;
				cout<<v<<" ";
			}

			for(int i : adj[v]) {
				if(!visited[i]) {
					stack.push_back(i);
				}
			}
		}
	}


	void BFS(int v) {
		vector<bool> visited(V,false);
		deque<int> queue;

		visited[v] = true;
		queue.push_back(v);

		while(!queue.empty()) {
			v = queue.front();
			cout<<v<<" ";
			queue.pop_front();

			for(int i : adj[v]) {
				if(!visited[i]) {
					visited[i] = true;
					queue.push_back(i);
				}
			}
		}
	}

	void findLevelOfEachNode(int v) {
		//finds the level of each node using BFS 	
		// v will be level 0		//this can be usde to find the shortest path between two nodes (shortest path = difference between levels)

		vector<bool> visited(V,false);
		vector<int> level(V,0);
		deque<int> queue;

		queue.push_back(v);
		visited[v] = true;

		while(!queue.empty()) {
			v = queue.front();
			queue.pop_front();

			for(int i : adj[v]) {
				if(!visited[i]) {
					visited[i] = true;
					level[i] = level[v] + 1;
					queue.push_back(i);
				}
			}
		}

		for(int i = 0; i<V; i++) {
			cout<<i<<" : "<<level[i]<<endl; 
		}
	}


	int findMotherVertex() {
		//If mother vertex exists it will be the last visited vertex by DFSutil (bcoz after it everything would have have been visited)
		//After that we have to check if the last visited vertex actually visits all the vertices

		vector<bool> visited(V,false);
		int lastVisited; 	//this will store the last visited vertex

		for(int i = 0; i<V; i++) {
			if(!visited[i]) {
				DFSutil(i,visited);
				lastVisited = i;		//update last visited
			}
		}

		//Check if lastVisited actually visits all vertices
		fill(visited.begin(),visited.end(),false);
		DFSutil(lastVisited,visited);
		for(int i = 0; i<V; i++) {
			if(!visited[i]){
				return -1;
			}
		}

		return lastVisited;
	}


	int countPaths(int u, int v) {
		vector<bool> visited(V,false);
		int pCount = 0;

		countPathsUtil(u,v,visited,pCount);
		return pCount;
	}

	void countPathsUtil(int u, int v, vector<bool> &visited, int &pCount) {
		//use backtracking i.e after everything make vertex unvisited again
		//if current vertex == destination vertex increment count

		visited[u] = true;

		if(u == v) {
			pCount++;
		} else {
			for(int i : adj[u]) {
				if(!visited[i]) {
					countPathsUtil(i, v, visited, pCount);
				}
			}
		}

		visited[u] = false;		// for backtracking,  so that another path can use this node again
	}

	bool isCyclic() {
		//a directed graph is cyclic if it has a back edge 
		//we do DFS and maintain a recursion stack
		//if there is an edge between current vertex and a vertex in the recursion stack then its cyclic 
		vector<bool> visited(V,false);
		vector<bool> recStack(V,false);

		for(int i = 0; i<V; i++) {
			if(isCyclicUtil(i, visited, recStack)) {
				return true;
			}
		}

		return false;
	}

	bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack) {
		if(!visited[v]) {
			visited[v] = true;
			recStack[v] = true;

			for(int i : adj[v]) {
				if(!visited[i] && isCyclicUtil(i, visited, recStack)) {
					return true;
				} else if(recStack[i]) {
					return true;
				}
			}
		}

		recStack[v] = false;
		return false;
	}

	bool isBipartite(int v) {	//for connected graph, for unconnected we need to call this for each component
		vector<int> color(V,-1);

		deque<int> queue;
		queue.push_back(v);
		color[v] = 1;

		while(!queue.empty()) {
			v = queue.front();
			queue.pop_front();

			for(int i : adj[v]) {
				if(color[i] == -1) {
					color[i] = 1 - color[v];
					queue.push_back(i);
				} else if(color[i] == color[v]) {	//color of parent is same as child
					return false;
				}
			}
		}

		return true;
	}

	bool isReachable(int u, int v) {
		if(u == v) {
			return true;
		}

		vector<int> visited(V,false);
		deque<int> queue;

		queue.push_back(u);
		visited[u] = true;

		while(!queue.empty()) {
			u = queue.front();
			queue.pop_front();

			for(int i : adj[u]) {
				if(i == v) {
					return true;
				}

				if(!visited[i]) {
					queue.push_back(i);
					visited[i] = true;
				}
			}
		}

		return false;
	}

	Graph getTranspose() {
		Graph newG(V);
		
		for(int v = 0; v<V; v++) {
			for(int i : adj[v]) {
				newG.adj[i].push_back(v);
			}
		}

		return newG;
	}

	//graph is strongly connected or not - https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/

};


// Algorithm to check if a graph is a eulerian circuit - hierholzer algorithm 
//euler path and cycle in undirected - https://www.geeksforgeeks.org/eulerian-path-and-circuit/
//euler cycle in directed - https://www.geeksforgeeks.org/euler-circuit-directed-graph/


int main() {

	int V;
	cin>>V;

	Graph g(V);

	int e,u,v;
	cin>>e;
	for(int i = 0; i<e; i++) {
		cin>>u>>v;
		g.addEdge(u,v);
	}

	cout<<g.isBipartite(0);
	return 0;
}