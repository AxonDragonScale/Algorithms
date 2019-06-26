// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

// Taking diameter as number of edges not number of nodes

pair<int, int> getHeightAndDiameter(unordered_map<int, vector<int>> &m, int root) {
    if (m[root].empty()) return {1, 0};  // leaf node height is 1, no edge so diameter is 0

    int maxDiameter = -1, curDiameter, maxHeight = INT_MIN, maxHeight2 = INT_MIN;
    for (int child : m[root]) {
        pair<int, int> p = getHeightAndDiameter(m, child);

        maxDiameter = max(maxDiameter, p.second);
        if (p.first > maxHeight) {
            maxHeight2 = maxHeight;
            maxHeight = p.first;
        } else if (p.first > maxHeight2) {
            maxHeight2 = p.first;
        }
    }

    if (m[root].size() >= 2)  // dont add one as diameter is nubmer of edges here not nodes
        curDiameter = maxHeight + maxHeight2;
    else
        curDiameter = maxHeight;

    return {1 + maxHeight, max(maxDiameter, curDiameter)};
}

int Solution::solve(vector<int> &parent) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < parent.size(); i++) {
        m[parent[i]].push_back(i);
    }

    return getHeightAndDiameter(m, m[-1][0]).second;
}