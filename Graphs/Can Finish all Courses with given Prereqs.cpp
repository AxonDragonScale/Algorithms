// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
// https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

bool isCyclic(vector<vector<int>> &adj, int cur, vector<bool> &visited, vector<bool> &onPath) {
    if (!visited[cur]) {
        visited[cur] = true;
        onPath[cur] = true;

        for (int i : adj[cur]) {
            if (!visited[i] && isCyclic(adj, i, visited, onPath)) {
                return true;
            } else if (onPath[i]) {
                return true;
            }
        }

        onPath[cur] = false;
    }

    return false;
}

int Solution::solve(int n, vector<int> &preReq, vector<int> &course) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < course.size(); i++) {  // Make edges from pre-reqs to courses
        adj[preReq[i]].push_back(course[i]);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> onPath(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && isCyclic(adj, i, visited, onPath)) {
            return 0;  // cant be done if there is a cycle
        }
    }

    return 1;
}
