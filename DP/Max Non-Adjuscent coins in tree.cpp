// Given a tree with a coin at each node, find max value possible if you cant pick
// coins from adjacent nodes

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

int coins[100];
vector<int> graph[100];

// method 1

int dontPick[100], pick[100];
void sol(int current, int parent) {
    for (auto child : graph[current]) {  // to make sure sol is already computed for children of current
        if (child != parent) {
            sol(child, current);
        }
    }

    pick[current] = coins[current];
    for (auto child : graph[current]) {
        if (child != parent) {
            pick[current] += dontPick[child];
            dontPick[current] += max(dontPick[child], pick[child]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // take input
    // run the function

    cout << max(dontPick[0], pick[0]);

    return 0;
}

// method 2

int dp[100];
void sol(int current, int parent) {      // c is child, p is parent
    for (auto child : graph[current]) {  // to make sure sol is already computed for children of c
        if (child != parent) {
            sol(child, current);
        }
    }

    int c1 = coins[current], c2 = 0;  // c1 = pickup, c2 = dont pick
    for (auto child : graph[current]) {
        if (child != parent) {
            c2 += dp[child];

            for (auto grandchild : graph[child]) {
                if (grandchild != current) {
                    c1 += dp[grandchild];
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    // take input
    // run the function

    cout << dp[0];

    return 0;
}