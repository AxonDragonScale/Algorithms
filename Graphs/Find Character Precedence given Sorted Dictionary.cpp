// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

void topologicalSort(vector<vi> &adj, vector<bool> &visited, stack<int> &stack, int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) topologicalSort(adj, visited, stack, v);
    }

    stack.push(u);
}

void findCharOrder(vector<string> &dict, int charsInAlphabet) {
    int wordsInDict = dict.size();

    vector<vi> adj(charsInAlphabet);
    for (int i = 0; i < wordsInDict - 1; i++) {
        for (int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++) {
            if (dict[i][j] != dict[i + 1][j]) {
                adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                break;
            }
        }
    }

    vector<bool> visited(charsInAlphabet, false);
    stack<int> stack;

    for (int i = 0; i < charsInAlphabet; i++) {
        if (!visited[i]) topologicalSort(adj, visited, stack, i);
    }

    cout << "The character precedence is :" << endl;
    while (!stack.empty()) {
        char c = 'a' + stack.top();
        cout << c << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    int wordsInDict, charsInAlphabet;
    cin >> wordsInDict >> charsInAlphabet;

    vector<string> dict(wordsInDict);
    for (int i = 0; i < wordsInDict; i++) {
        cin >> dict[i];
    }

    findCharOrder(dict, charsInAlphabet);

    return 0;
}
