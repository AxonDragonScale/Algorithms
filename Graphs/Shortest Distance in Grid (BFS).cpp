// BFS on a grid to find shortest path from s to d
// s is source, d is destination, 0 is blocked path, . is open path

// https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

#define LN cout<<__LINE__<<endl

struct Node {
	int row;
	int col;
	int dist;	// distance from the source

	Node(int r, int c, int d) : row(r), col(c), dist(d) {	}
};

using namespace std;

int main() {

	int rows, cols;
	cin>>rows>>cols;

	Node src(0,0,0);

	char grid[rows][cols];
	bool visited[rows][cols];
	for(int i = 0; i<rows; i++) {
		for(int j = 0; j<cols; j++) {
			cin>>grid[i][j];

			if(grid[i][j] == '0') {	// 0 is blocked // By keeping blocked as visited, we can just ignore them
				visited[i][j] = true;
			} else if(grid[i][j] == 's') {
				src.row = i;
				src.col = j;
				visited[i][j] = false;
			} else {
				visited[i][j] = false;
			}
		}
	}

	// BFS
	deque<Node> queue;
	queue.push_back(src);
	visited[src.row][src.col] = true;

	bool found = false;

	while(!queue.empty()) {
		Node n = queue.front();
		queue.pop_front();

		if(grid[n.row][n.col] == 'd') {
			cout<<n.dist<<endl;
			found = true;
			break;
		}

		if(n.row-1 >= 0 && visited[n.row-1][n.col] == false) {		// move up
			queue.push_back(Node(n.row-1, n.col, n.dist+1));
			visited[n.row-1][n.col] = true;
		}

		if(n.row+1 < rows && visited[n.row+1][n.col] == false) {	// move down
			queue.push_back(Node(n.row+1, n.col, n.dist+1));
			visited[n.row+1][n.col] = true;
		}

		if(n.col-1 >= 0 && visited[n.row][n.col-1] == false) {		// move left
			queue.push_back(Node(n.row, n.col-1, n.dist+1));
			visited[n.row][n.col-1] = true;
		}

		if(n.col+1 < cols && visited[n.row][n.col+1] == false) {	// move right
			queue.push_back(Node(n.row, n.col+1, n.dist+1));
			visited[n.row][n.col+1] = true;
		}

	}

	if(found == false) {
		cout<<-1<<endl;
	}


	return 0;
}