// https://www.interviewbit.com/problems/shortest-unique-prefix/

struct Node {
    map<char, pair<Node *, int>> m;
};

vector<string> Solution::prefix(vector<string> &words) {
    vector<string> ans;
    Node *root = new Node;

    for (string word : words) {
        Node *cur = root;
        for (char c : word) {
            if (cur->m.find(c) != cur->m.end()) {
                cur->m[c].second++;
                cur = cur->m[c].first;
            } else {
                cur->m[c].first = new Node;
                cur->m[c].second = 1;
                cur = cur->m[c].first;
            }
        }
    }

    for (string word : words) {
        Node *cur = root;
        string s;
        for (char c : word) {
            s.push_back(c);
            if (cur->m[c].second != 1) {
                cur = cur->m[c].first;
            } else {
                break;
            }
        }

        ans.push_back(s);
    }

    return ans;
}

// TODO -> https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
// TODO -> https://www.geeksforgeeks.org/find-shortest-unique-prefix-every-word-given-list-set-2-using-sorting/