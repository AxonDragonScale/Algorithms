// https://www.geeksforgeeks.org/job-sequencing-problem/

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

struct Job {
    int id;
    int deadline;
    int profit;
};

struct DSU {
    deque<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {  // 1 based indexing, parent[0] is garbage value.
            parent[i] = i;
        }
    }

    int root(int i) {  // returns root of i
        if (i == parent[i]) {
            return i;
        }

        parent[i] = root(parent[i]);  // path compression (save root so we dont have to do again next time)
        // Using recursive version also saves root of intermediate elements as well, so better path compression
        return parent[i];
    }

    bool find(int a, int b) {  // checks if both a and b are in the same set
        return root(a) == root(b);
    }

    void connect(int a, int b) {  // usually called union (union is a keyword in c++)
        int aRoot = root(a);
        int bRoot = root(b);

        parent[bRoot] = aRoot;
    }
};

bool comparator(const Job &a, const Job &b) { return a.profit > b.profit; }

int main() {
    int n, tId, tDeadline, tProfit, maxDeadline = 0;
    cin >> n;

    deque<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> tId >> tDeadline >> tProfit;
        jobs[i] = {tId, tDeadline, tProfit};
        maxDeadline = max(tDeadline, maxDeadline);
    }

    sort(jobs.begin(), jobs.end(), comparator);  // sort on profit

    DSU dsu(maxDeadline);

    for (int i = 0; i < n; i++) {
        int freeSlot = dsu.root(jobs[i].deadline);  // it will be deadline slot or an empty slot before it

        if (freeSlot > 0) {
            dsu.connect(dsu.root(freeSlot - 1), freeSlot);
            cout << jobs[i].id << " ";
        }
        // root(freeSlot -1) is free, so now jobs with deadline as freeSlot will go to root(freeSlot - 1)
    }

    return 0;
}