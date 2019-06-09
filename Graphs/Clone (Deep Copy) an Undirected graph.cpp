// https://www.interviewbit.com/problems/clone-graph/

// Also see Iterative(BFS) solution in InterviewBit

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode *util(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &vis) {
    if (vis.find(node) != vis.end()) return vis[node];

    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    vis[node] = root;

    for (UndirectedGraphNode *child : node->neighbors) {
        root->neighbors.push_back(util(child, vis));
    }

    return root;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> vis;
    return util(node, vis);
}
