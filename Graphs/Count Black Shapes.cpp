// https://www.interviewbit.com/problems/black-shapes/

// Another Approach - Use BFS
// start a BFS every time we get a 'X' and visit all neighbouring Xs, dont visit Os
// change all visited X to O and increase count every time we have to start a BFS
// SEE INTERVIEWBIT SOLUTION FOR THIS APPROACH

// Approach 1
// This solution uses Union Find algo to mark all connected components
int root(vector<int> &parent, int i) {
    while (i != parent[i]) {
        i = parent[i];
    }

    return i;
}

void connect(vector<int> &parent, int a, int b) { parent[root(parent, b)] = root(parent, a); }

int Solution::black(vector<string> &grid) {
    int r = grid.size();
    int c = grid[0].size();

    vector<int> parent(r * c, -1);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'X') {
                parent[i * c + j] = i * c + j;

                if (i - 1 >= 0 && grid[i - 1][j] == 'X') connect(parent, (i - 1) * c + j, i * c + j);
                if (j - 1 >= 0 && grid[i][j - 1] == 'X') connect(parent, i * c + j - 1, i * c + j);
            }
        }
    }

    int cnt = 0;
    unordered_set<int> roots;
    for (int i : parent) {
        if (i != -1) {
            if (roots.find(root(parent, i)) == roots.end()) {
                cnt++;
                roots.insert(root(parent, i));
            }
        }
    }

    return cnt;
}