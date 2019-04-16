
// https://www.geeksforgeeks.org/fractional-knapsack-problem/

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
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

struct Item {
    int val;
    int weight;
};

bool comparator(const Item &a, const Item &b) { return (a.val / (float)a.weight) > (b.val / (float)b.weight); }

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, w, tValue, tWeight;
        cin >> n >> w;

        vector<Item> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> tValue >> tWeight;
            arr[i] = {tValue, tWeight};
        }

        sort(arr.begin(), arr.end(), comparator);

        float curVal = 0, curWeight = 0, i = 0;
        while (curWeight < w && i < n) {
            if (curWeight + arr[i].weight <= w) {
                curWeight += arr[i].weight;
                curVal += arr[i].val;
            } else {
                int remainingWeight = w - curWeight;
                curWeight = w;
                curVal += arr[i].val * (remainingWeight / (float)arr[i].weight);
            }

            i++;
        }

        cout << fixed << setprecision(2) << curVal << endl;
    }

    return 0;
}